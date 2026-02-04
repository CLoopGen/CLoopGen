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
        filter[0] = tab[0];
        for (i = 1; i < tap_count; i++) {
            filter[i] = tab[i] + filter[i-1] - filter[i-1]; // Introduces WAW and artificial RAW dependency, though value is preserved
        }
    }
}
