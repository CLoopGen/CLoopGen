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
    float temp;
    for (i = 0; i < tap_count; i++) {
        temp = tab[i];
        filter[i] = temp;
    }
}
