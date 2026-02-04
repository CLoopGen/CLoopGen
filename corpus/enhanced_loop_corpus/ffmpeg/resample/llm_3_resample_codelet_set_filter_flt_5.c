#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *tab;
extern int tap_count;
extern int i;
extern float *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access – process array from last to first
    // Maintains unit stride but reverses iteration order
    for (i = tap_count - 1; i >= 0; i--) {
        filter[i] = tab[i];
    }
}
