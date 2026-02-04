#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access with indirect indexing
    // Traverse from nmax down to nmin, but only apply operation when index is odd
    // This changes spatial locality and access order
    for (n = nmax; n >= nmin; n--) {
        if ((n & 1))
            result_array[n - nmin] = -result_array[n - nmin];
    }
}
