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
    for (i = 1; i < tap_count; i++) {
        filter[i] = tab[i] + filter[i-1];
    }
    if (tap_count > 0) {
        filter[0] = tab[0];
    }
}
