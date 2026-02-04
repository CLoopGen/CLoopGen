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
    int outer = tap_count > 0 ? 1 : 0;
    for (i = 0; i < outer; i++) {
        int j;
        for (j = 0; j < tap_count; j++) {
            filter[j] = tab[j];
        }
    }
}
