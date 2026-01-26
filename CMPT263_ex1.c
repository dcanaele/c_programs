/* 
 * File: CMPT263_ex1 main module for dist function
 * Author: Daniel Anaele
 * Date: 1/21/2026
 * Description: nDist function and regression tests in main module
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* structure to contain a value's frequency
 * Noticed it would not be necessary for this problem but too late now */
typedef struct _numc {
	int value;
	uint64_t count;
} Numc;

/* Function to determine nDist
 * Preconditions: 
 * 	* A: Array of integers (possibly with duplicate values)
 * 	* n: non-negative 64 bit integer
 * Postconditions:
 * 	* A and n remain unchanged
 * Return: nDist: non-negative 64 bit integer
 * 	* number of distinct values in A in the subscript range from 0 to n-1, inclusive.
*/
uint64_t dist( int* A, uint64_t n ) 
{
	if (n == 0) return 0;

	Numc dist_arr[n];
	dist_arr[0] = (Numc){ A[0], 1 };
	uint64_t l=1;
	int found;

	for (uint64_t i=1; i<n; i++) {

		found = 0;
		
		for (uint64_t j=0; j<l; j++) {
			if (dist_arr[j].value == A[i]) {
				dist_arr[j].count++;
				found = 1;
				break;
			}
		}
		
		if (!found) dist_arr[l++] = (Numc){ A[i], 1 };
	}
	return l;
}


int main(void) 
{
	int A[] = {45, 13, -15, 13, 13, 45};
	uint64_t n = 6;

	int nDist = dist(A, n);
	
	printf("A = ");
	for ( int i=0; i<6; i++ ) {
		printf("%d ", A[i]);
	}

	printf("\nn = %ld\n", n);
	printf("nDist = %d\n", nDist);
	
	return 0;
}
