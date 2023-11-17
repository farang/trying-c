#include <stdio.h>
#include <sys/stat.h>
#include "../include/entity-type.h"

int createEntity(enum EntityType type, char *name)
{
    FILE *filePointer;

    switch (type)
    {
    case Directory:
        if (mkdir(name, 0777) == 0)
        {
            return 0;
        }
        return 1;
        break;
    case File:
        filePointer = fopen(name, "w");

        if (filePointer == NULL)
        {
            return 1;
        }

        fclose(filePointer);
        return 0;
        break;
    }
    return 1;
}