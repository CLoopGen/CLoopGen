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
    int j;
    for (i = 0; i < width * 2; i += 2) {
        DWTELEM val0, val1, val2;
        int idx = i % width;
        val0 = b0[idx];
        val1 = b1[idx];
        val2 = b2[idx];
        b1[idx] = (64 * val1 - 4 * (val0 + val2) + 40 + (5 << 27)) / 80 - (1 << 23);
    }
}
