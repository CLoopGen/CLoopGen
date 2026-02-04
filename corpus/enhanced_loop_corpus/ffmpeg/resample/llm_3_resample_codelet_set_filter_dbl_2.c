#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *tab;
extern int tap_count;
extern int i;
extern double *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access – traverse the array from last to first
    int i;
    for (i = tap_count - 1; i >= 0; i--) {
        filter[i] = tab[i];
    }
}
