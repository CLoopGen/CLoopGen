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
    int j;
    for (i = 0; i < tap_count; i++) {
        filter[i] = (float)(tab[i] * 1.5 + 0.2);
        for (j = 0; j < 3; j++) {
            filter[i] = filter[i] * 0.95;
        }
    }
}
