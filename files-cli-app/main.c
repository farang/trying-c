#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "include/entity-tools.h"
#include "include/text-tools.h"

int main()
{
	// entity type to create
	char userInput[10];

	printf("enter what you want to create: d(directory), f(folder):\n");
	fgets(userInput, sizeof(userInput), stdin);
	removeLineBreaks(userInput);

	char message[100];
	enum EntityType entityToCreate;
	char entityName[100];

	if (strcmp(userInput, "d") == 0)
	{
		entityToCreate = Directory;
		strcat(message, "Directory ");
	}
	else if (strcmp(userInput, "f") == 0)
	{
		entityToCreate = File;
		strcat(message, "File ");
	}
	else
	{
		perror(userInput);
		return 1;
	}
	strcat(message, "will be created.\n");

	// entity name
	printf("Enter name:\n");
	fgets(entityName, sizeof(entityName), stdin);

	// if file creation requested, create and stop execution
	if (entityToCreate == File)
	{
		if (createEntity(entityToCreate, entityName) == 0)
		{
			printf("successfully created file");
			return 0;
		}
		perror("failed to create file");
		return 1;
	}

	// check if subitem shoud be created
	printf("Do you want to create subitems?(y/n)\n");
	fgets(userInput, sizeof(userInput), stdin);

	if (strcmp(userInput, "y") == 0)
	{
		char namesList[400];
		printf("Enter subitems names. [name].[extension],[name].[extension]...\n");
		fgets(namesList, sizeof(namesList), stdin);
		removeLineBreaks(namesList);

		const char separator[] = ",";
		char *fileName = strtok(namesList, separator);

		while (fileName != NULL)
		{
			char path[100];
			strcpy(path, entityName);
			strcat(path, "/");
			strcat(path, fileName);
			createEntity(File, path);
			fileName = strtok(namesList, separator);
		}
	}
	else
	{
		if (createEntity(entityToCreate, entityName) == 0)
		{
			printf("successfully created");
		}
		else
		{
			perror("failed to create");
		}
	}

	return 0;
}
