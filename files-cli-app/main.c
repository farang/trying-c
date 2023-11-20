#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "include/entity-tools.h"
#include "include/text-tools.h"

int main()
{
	const int maxCommandInputSize = 10;
	const int maxMessageInputSize = 100;
	const int maxEntityNameInputSize = 100;
	const int maxFilesListInputSize = 400;
	const int maxFilePathInputSize = 100;

	// entity type to create
	char userInput[maxCommandInputSize];

	printf("enter what you want to create: d(directory), f(folder):\n");
	fgets(userInput, sizeof(userInput), stdin);
	removeLineBreaks(userInput);

	char message[maxMessageInputSize] = "";
	enum EntityType entityToCreate;
	char entityName[maxEntityNameInputSize];

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
		return fprintf(stderr, "wrong value provided: %s\n", userInput);
	}
	strcat(message, "will be created.\n");

	// entity name
	printf("Enter name:\n");
	fgets(entityName, sizeof(entityName), stdin);
	removeLineBreaks(entityName);

	// if file creation requested, create and stop execution
	if (entityToCreate == File)
	{
		if (createEntity(entityToCreate, entityName) == 0)
		{
			printf("successfully created file\n");
			return 0;
		}
		return fprintf(stderr, "failed to create file with name: %s\n", entityName);
	}

	// check if subitem should be created
	printf("Do you want to create subitems?(y/n)\n");
	fgets(userInput, sizeof(userInput), stdin);
	removeLineBreaks(userInput);

	if (strcmp(userInput, "y") == 0)
	{
		if (createEntity(entityToCreate, entityName) != 0)
		{
			return fprintf(stderr, "failed to create directory: %s\n", entityName);
		}

		char namesList[maxFilesListInputSize];
		printf("Enter subitems names. [name].[extension],[name].[extension]...\n");
		fgets(namesList, sizeof(namesList), stdin);
		removeLineBreaks(namesList);

		const char separator[] = ",";
		char *fileName = strtok(namesList, separator);

		while (fileName != NULL)
		{
			char path[maxFilePathInputSize];
			strcpy(path, entityName);
			strcat(path, "/");
			strcat(path, fileName);
			if (createEntity(File, path) != 0)
			{
				return fprintf(stderr, "failed to create file: %s\n", fileName);
			}
			fileName = strtok(NULL, separator);
		}
	}
	else
	{
		if (createEntity(entityToCreate, entityName) == 0)
		{
			printf("successfully created\n");
		}
		else
		{
			return fprintf(stderr, "failed to create: %s\n", entityName);
		}
	}

	return 0;
}
