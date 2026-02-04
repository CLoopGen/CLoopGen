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
    for (i = 1; i < width; i++) {
        b1[i] += (1 * (b0[i-1] + b2[i]) + 0) >> 0;
    }
    if (width > 0) {
        b1[0] += (1 * (b0[0] + b2[0]) + 0) >> 0;
    }
}
