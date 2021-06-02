#include <stdio.h>
int main(int argc, char** argv)
{
	int N; // Enter size of the Pattern
	printf("Enter the size of N: \t");
	scanf("%d", &N);
	if (N<3)
	printf("This is not making pattern N \n");
	int i, spc;
	for (i = 0; i < N; i++) {
    // To print the left N's
		printf("N");
		// To print the diagonal N's
		for (spc = 0; spc < 2 * (i); spc++)
			printf(" ");
		if (i != 0 && i != N - 1) 
			printf("N");
		else
			printf(" ");
		// Spaces for the Right N's
		for (spc = 0; spc < 2 * (N - i - 1); spc++)
			printf(" ");
		// To print the right N's
		printf("N");

		printf("\n");
}
}
