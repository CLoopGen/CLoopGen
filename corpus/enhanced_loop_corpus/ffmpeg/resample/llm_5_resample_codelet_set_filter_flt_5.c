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
    for (i = 0; i < tap_count; i++) {
        if (tab[i] >= 0.0) {
            filter[i] = tab[i];
        } else {
            filter[i] = 0.0f;
        }
    }
}
