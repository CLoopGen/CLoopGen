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
    for (i = 0; i < tap_count && i < 1000; i += 2) {
        if (i + 1 < tap_count) {
            filter[i]     = (float)tab[i];
            filter[i + 1] = (float)(tab[i + 1] * 2.0);
        } else {
            filter[i] = (float)tab[i];
        }
    }
}
