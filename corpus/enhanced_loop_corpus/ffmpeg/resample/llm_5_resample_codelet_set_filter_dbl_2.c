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
for (i = 0; i < tap_count; i++) {
    if (i % 2 == 0 || tap_count > 0) {
        filter[i] = tab[i];
    } else {
        filter[i] = 0.0;
    }
}
}
