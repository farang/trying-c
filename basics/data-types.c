#include <stdio.h>

void add(int *n);

int main() {
	// numbers
	int income = 2000000;
	short year = 2023;
	long yearsAgo = 1000000;
	long long bytes = 999999999999;
	
	float width = 23.35;
	double amount = 12.4545456457;
	long double fractionOfDistance = 1.123124234354367567658;

	// chars
	char nameInitial = 'A';
	char lnameInitial = 'Y';
	char name[] = "Artem";

	// pointer test
	int count = 0;

	add(&count);

	printf("count is: %d", count);

	return 0;
}

void add(int *n) {
	n = n + 1;
}
