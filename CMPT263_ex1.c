/* 
 * File: CMPT263_ex1 main module for dist function
 * Author: Daniel Anaele
 * Date: 1/21/2026
 * Description: nDist function and regression tests in main module
*/

#include <stdio.h>
#include <stdlib.h>

/* structure to contain a value's frequency
 * Noticed it would not be necessary for this problem but too late now */
struct _numc {
	int value;
	uint64_t count;
} typedef Numc;

/* Function to determine nDist
 * Preconditions: 
 * 	* A: Array of integers (possibly with duplicate values)
 * 	* n: non-negative 64 bit integer
 * Postconditions:
 * 	* A and n remain unchanged
 * Return: nDist: non-negative 64 bit integer
 * 	* number of distinct values in A in the subscript range from 0 to n-1, inclusive.
*/
uint64_t dist( int[] A, uint64_t n ) 
{
	Numc dist[n];
	dist[0] = { A[0], 1 };
	int l=1;

	for (int i=0; i<n; ++i) {
		for (int j=0; j<l; j++) {
			if (dist[j].value == A[i])
				dist[j].count++;
			else
				dist[l++] = { A[i], 1 };
				break;
		}
	}
	return l;
}


int main(int argc, char *argv[]) 
{
	int A[] = [45, 13, -15, 13, 13, 45];
	uint64_t n = 6;

	int nDist = dist(A, n);
	
	printf("A = ");
	for ( int i=0; i<6; i++ ) {
		printf("%d ", A[i]);
	}

	printf("n = %d\n", n);
	printf("nDist = %d\n", nDist);
	
	return 0;
}
