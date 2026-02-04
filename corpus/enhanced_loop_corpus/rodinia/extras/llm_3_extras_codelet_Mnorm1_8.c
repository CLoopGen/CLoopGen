#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern int i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential memory access
    for (i = len - 1; i >= 0; i--)
        sum += ((x[i]) >= 0 ? (x[i]) : -(x[i]));
}
