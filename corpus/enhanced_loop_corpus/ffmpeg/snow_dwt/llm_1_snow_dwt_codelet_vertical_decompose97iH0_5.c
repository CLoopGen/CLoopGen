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
    int stride = 4;
    for (i = 0; i < width; i += stride) {
        for (int k = 0; k < stride && (i + k) < width; k++) {
            int idx = i + k;
            b1[idx] -= (3 * (b0[idx] + b2[idx]) + 0) >> 1;
        }
    }
}
