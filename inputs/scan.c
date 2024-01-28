#include <stdio.h>

int main()
{
    char firstName[120];
    char lastName[120];
    int age;

    printf("Enter your first name, last name and age:\n");

    scanf("%s%s%d", firstName, lastName, &age);

    FILE *file = fopen("./user.txt", "w");
    char fileContent[200];

    sprintf(fileContent, "\nYour name is %s %s.\nYou was born in %d.\n", firstName, lastName, age);

    fprintf(file, "%s", fileContent);
    fclose(file);

    return 0;
}