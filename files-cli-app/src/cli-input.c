#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../include/entity-type.h"
#include "./../include/text-tools.h"

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

enum EntityType getEntityTypeInput(int size)
{
    char *input = getInputWithNoBreaks(size);

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

int actionConfirmed(const char *confirmationValue, int size)
{
    char *input = getInputWithNoBreaks(size);
    return strcmp(input, confirmationValue);
}
