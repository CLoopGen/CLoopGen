#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double lower;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    int indices[9] = {8, 7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order access
    for (i = 0; i < 9; i++) {
        a[indices[i]] = lower;
    }
}
