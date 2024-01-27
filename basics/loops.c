#include <stdio.h>

int ids[] = {1, 2, 3, 4, 5, 6, 7};

int main()
{
    // for loop
    int count = sizeof(ids) / sizeof(ids[0]);

    for (int i = 0; i < count; i++)
    {
        printf("for %d\n", ids[i]);
    }

    // while loop
    int i = 1;

    while (i < 8)
    {
        printf("while %d\n", i);
        i++;
    }

    // do while
    int i2 = 1;

    do
    {
        printf("do while %d\n", i2);
        i2++;
    } while (i2 < 8);

    int i3 = 0;

    do
    {
        printf("executed at least once");
    } while (i3 > 0);

    return 0;
}
