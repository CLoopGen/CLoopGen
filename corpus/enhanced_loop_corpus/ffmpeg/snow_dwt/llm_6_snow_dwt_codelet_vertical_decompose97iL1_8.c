#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *b0;
extern DWTELEM *b1;
extern DWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    DWTELEM * restrict r_b0 = b0;
    DWTELEM * restrict r_b1 = b1;
    DWTELEM * restrict r_b2 = b2;
    int w = width;
    for (i = 0; i < w; i++) {
        DWTELEM temp_sum = r_b0[i] + r_b2[i];
        r_b1[i] += (3 * temp_sum + 4) >> 3;
    }
}
