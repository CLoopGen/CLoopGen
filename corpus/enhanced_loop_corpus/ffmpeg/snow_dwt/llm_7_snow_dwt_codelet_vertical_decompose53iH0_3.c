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
    DWTELEM * restrict r_b1 = b1;
    const DWTELEM * restrict r_b0 = b0;
    const DWTELEM * restrict r_b2 = b2;
    int w = width;
    DWTELEM prev_adjust = 0;
    for (i = 0; i < w; i++) {
        DWTELEM curr_val = (r_b0[i] + r_b2[i]) >> 1;
        DWTELEM adjusted_val = curr_val + prev_adjust;
        r_b1[i] -= adjusted_val;
        prev_adjust = curr_val;
    }
}
