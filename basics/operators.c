#include <stdio.h>

void nextMonth(int *month)
{
    *month += 1;
    *month = *month <= 12 ? *month : 12;
}

int main()
{
    // Assignment operator
    int month = 5;
    printf("initial value %d\n", month);
    // Substract AND assignment operator
    month -= 1;
    // Add AND assignment operator
    month += 12;
    // Multiply AND assignment operator
    month *= 1;
    // Divide AND assignment operator
    month /= 1;
    // Sizeof operator
    size_t monthVarSize = sizeof(month);

    // Conditional expression
    int fixedMonth = month <= 12 ? month : 12;
    // Address variable
    int *monthReferrence = &fixedMonth;

    // Pointer arguments usage
    nextMonth(monthReferrence);

    printf("final value %d\n", fixedMonth);

    return 0;
}