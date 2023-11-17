#include <stdio.h>

enum Drink {
    Tea,
    Coffee
};

int main() {
    int month = 9;

    // if statement
    if (month == 9) {
    	printf("It's September\n");
    }

    // if-else statement
    if (month == 9) {
    	printf("it's September\n");
    } else {
    	printf("some other month\n");
    }

    // if-else if-else statemnt
    if (month == 9) {
        printf("it's September\n");
    } else if (month == 10) {
    	printf("it's October\n");
    } else {
    	printf("some other month\n");
    }

    // switch statement
    enum Drink choosenDrink = Tea;

    switch (choosenDrink) {
    	case Tea:
	    printf("drink tea\n");
	    break;
	case Coffee:
	    printf("drink coffee\n");
	    break;
	default:
	    printf("some other drink\n");
	    break;
    }

    return 0;
}
