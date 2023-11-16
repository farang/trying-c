#include <stdio.h>

int ids[] = {1,2,3,4,5,6,7};

int main() {
    // for loop
    int count = sizeof(ids) / sizeof(ids[0]);

    for (int i = 0; i < count; i++) {
        printf("for %d\n", ids[i]);
    }

    // while loop
    int i = 1;

    while(i < 8) {
        printf("while %d\n", i);
	i++;
    }

    return 0;	
}

