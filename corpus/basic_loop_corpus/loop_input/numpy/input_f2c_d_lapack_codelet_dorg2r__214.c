#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
integer *k;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer j;
integer l;

void init_vars() {
    // Allocate and initialize scalar parameters
    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    
    *m = 5000;
    *k = 1000;
    i__1 = 2000;
    a_dim1 = 2000;  // leading dimension of 2D array 'a'

    // Allocate 2D array 'a' as a contiguous block: dimensions [a_dim1+1][a_dim1+1] to allow 1-based indexing
    // We use 1-based indexing as implied by loop starting at 1 (l=1, j=1)
    a = (doublereal*)calloc((a_dim1 + 1) * (a_dim1 + 1), sizeof(doublereal));

    // Ensure that the loop bounds are safe:
    // j from *k+1 to i__1 => 1001 to 2000
    // l from 1 to *m => 1 to 5000, but must not exceed a_dim1 in indexing
    // So we require *m <= a_dim1 -> 5000 <= 2000 is false -> adjust

    // Fix: Make *m <= a_dim1. Adjust *m to valid size.
    *m = 2000;  // now l goes from 1 to 2000, and a_dim1 is 2000 -> valid index

    // Also ensure i__1 <= a_dim1 to prevent out-of-bounds in a[j + j*a_dim1]
    i__1 = 2000; // already set, must be <= a_dim1
}