#include <stdio.h>

int main(void) 
{
	#define MAX 256		/* maximum number of entries, > 0			*/
	typedef int Entry; 	/* type of entries, use == for equality		*/
	int n;				/* number of entries						*/
	Entry A[MAX];		/* A[0:n-1] are the entries					*/
	int nDist;			/* number of distinct entries in A[0:n-1]	*/

	printf("Enter n: ");
	if (scanf("%d", &n) != 1) error("input failure");
	if (n<0) error("n must be a non-negative");
	if (n > max) error("n must be <= max");
	if (n>0) {
		int i;
		printf("Enter components of A[0:n-1], ");
		printf("separated by white space:\n");
		for (i=0; i<n; i++)
			if (scanf("%i", &A[i]) != 1) error("input failure");
	}

	ASSERT( 0 <= n <= max )

	# include "cmpt263_ex1.i"

	ASSERT( nDist == |A[0:n-1]| )

	printf("Number of distinct components in A[0:n-1] is ");
	printf("%i\n", nDist);
	return 0;
}
