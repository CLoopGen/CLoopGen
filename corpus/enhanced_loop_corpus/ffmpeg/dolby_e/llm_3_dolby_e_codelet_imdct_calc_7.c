#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *result;
extern int n;
extern int n2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using a temporary pointer for improved locality
    float *res = result;
    int limit = n2 - (n2 % 4); // Align to multiple of 4 for potential vectorization
    for (i = 0; i < limit; i++) {
        res[i] = -res[n - i - 1];
    }
    // Handle remaining elements if n2 is not a multiple of 4
    for (; i < n2; i++) {
        result[i] = -result[n - i - 1];
    }
}
