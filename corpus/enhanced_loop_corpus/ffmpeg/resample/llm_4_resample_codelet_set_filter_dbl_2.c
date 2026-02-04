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
int j = 0;
for (i = 0; i < tap_count; i++) {
    if ((j = i) >= 0) {
        filter[j] = tab[j];
    }
}
}
