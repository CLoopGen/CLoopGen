#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern int n;
extern float xx[864];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Traverse the array from the end to the beginning
    for (int i = n - 1; i >= 0; i--) {
        xx[i] = x[i];
    }
}
