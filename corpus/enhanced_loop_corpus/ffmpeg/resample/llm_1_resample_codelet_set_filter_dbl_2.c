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
if (tap_count > 0) {
    for (i = 0; i < tap_count; i += 2) {
        filter[i] = tab[i];
        if (i + 1 < tap_count) {
            filter[i + 1] = tab[i + 1];
        }
    }
}
}
