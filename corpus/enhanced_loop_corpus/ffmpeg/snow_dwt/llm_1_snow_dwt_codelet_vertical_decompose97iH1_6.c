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
    int outer = width / 2;
    int remainder = width % 2;
    for (i = 0; i < outer; i++) {
        b1[2*i]     += (1 * (b0[2*i]     + b2[2*i])     + 0) >> 0;
        b1[2*i + 1] += (1 * (b0[2*i + 1] + b2[2*i + 1]) + 0) >> 0;
    }
    if (remainder) {
        b1[width - 1] += (1 * (b0[width - 1] + b2[width - 1]) + 0) >> 0;
    }
}
