#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "include/entity-tools.h"
#include "include/text-tools.h"
#include "include/cli-input.h"

#define maxCommandInputSize 10
#define maxEntityTypeInputSize 100
#define maxEntityNameInputSize 100
#define maxFilesListInputSize 400
#define maxFilePathInputSize 800

int main()
{
	// 1. handle entity type input
	printf("enter what you want to create: d(directory), f(folder):\n");
	const enum EntityType entityToCreate = getEntityTypeInput(maxEntityTypeInputSize);

	if (entityToCreate == Unknown)
	{
		return fprintf(stderr, "wrong entity entered: %d\n", entityToCreate);
	}

	// 2. handle entity name input
	printf("Enter name:\n");
	const char *entityName = getInputWithNoBreaks(maxEntityNameInputSize);

	if (strcmp(entityName, "") == 0)
	{
		fprintf(stderr, "name can't be empty: %s\n", entityName);
		free((void *)entityName);
		return -1;
	}

	// 3. create file because no children can be added
	if (entityToCreate == File)
	{
		printf("create file");
		if (createEntity(entityToCreate, entityName) != 0)
		{
			fprintf(stderr, "failed to create file: %s\n", entityName);
			free((void *)entityName);
			return -1;
		}

		printf("created file");
		free((void *)entityName);
		return 0;
	}

	// 4. ask if subitem should be created inside the directory
	printf("Do you want to create subitems?(y/n)\n");

	if (actionConfirmed("y", maxCommandInputSize) == 0)
	{
		// 5. handle children input
		printf("Enter subitems names. [name].[extension],[name].[extension]...\n");

		char *fileNamesList = getInputWithNoBreaks(maxFilesListInputSize);
		const char *separator = ";";
		char *fileName = strtok(fileNamesList, separator);

		// 5.1 create folder
		if (createEntity(Directory, entityName) != 0)
		{
			fprintf(stderr, "failed to create directory: %s\n", entityName);
			free((void *)entityName);
			return -1;
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
				fprintf(stderr, "failed to create file: %s\n", fileName);
				free((void *)entityName);
				free(fileNamesList);
				free(fileName);
				return -1;
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
			fprintf(stderr, "failed to create: %s\n", entityName);
			free((void *)entityName);
			return -1;
		}
	}

	free((void *)entityName);
	return 0;
}
