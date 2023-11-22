#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "include/entity-tools.h"
#include "include/text-tools.h"

#define maxCommandInputSize 10
#define maxEntityTypeInputSize 100
#define maxEntityNameInputSize 100
#define maxFilesListInputSize 400
#define maxFilePathInputSize 800

char *getInputWithNoBreaks(size_t size)
{
	char *input = malloc(size);

	if (input == NULL)
	{
		// Handle allocation failure
		fprintf(stderr, "Memory allocation failed\n");
	}

	fgets(input, size, stdin);
	removeLineBreaks(input);
	return input;
}

enum EntityType getEntityTypeInput()
{
	char *input = getInputWithNoBreaks(maxEntityTypeInputSize);

	if (strcmp(input, "d") == 0)
	{
		return Directory;
	}
	if (strcmp(input, "f") == 0)
	{
		return File;
	}

	return Unknown;
}

int actionConfirmed(const char *confirmationValue)
{
	char *input = getInputWithNoBreaks(maxCommandInputSize);
	return strcmp(input, confirmationValue);
}

int main()
{
	// 1. handle entity type input
	printf("enter what you want to create: d(directory), f(folder):\n");
	const enum EntityType entityToCreate = getEntityTypeInput();

	if (entityToCreate == Unknown)
	{
		return fprintf(stderr, "wrong entity entered: %d\n", entityToCreate);
	}

	// 2. handle entity name input
	printf("Enter name:\n");
	const char *entityName = getInputWithNoBreaks(maxEntityNameInputSize);

	if (strcmp(entityName, "") == 0)
	{
		return fprintf(stderr, "name can't be empty: %s\n", entityName);
	}

	// 3. create file because no children can be added
	if (entityToCreate == File)
	{
		printf("create file");
		if (createEntity(entityToCreate, entityName) != 0)
		{
			printf("failed create file");
			return fprintf(stderr, "failed to create directory: %s\n", entityName);
		}

		printf("created file");
		return 0;
	}

	// 4. ask if subitem should be created inside the directory
	printf("Do you want to create subitems?(y/n)\n");

	if (actionConfirmed("y") == 0)
	{
		// 5. handle children input
		printf("Enter subitems names. [name].[extension],[name].[extension]...\n");

		char *fileNamesList = getInputWithNoBreaks(maxFilesListInputSize);
		const char *separator = ";";
		char *fileName = strtok(fileNamesList, separator);

		// 5.1 create folder
		if (createEntity(Directory, entityName) != 0)
		{
			return fprintf(stderr, "failed to create directory: %s\n", entityName);
		}

		// 5.2 create children
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
