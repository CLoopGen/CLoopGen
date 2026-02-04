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
    int outer_i;
    for (outer_i = 0; outer_i < width; outer_i += 16) {
        for (i = outer_i; i < width && i < outer_i + 16; i++)
            b1[i] = (16 * 4 * b1[i] - 4 * (b0[i] + b2[i]) + 8 * 5 + (5 << 27)) / (5 * 16) - (1 << 23);
    }
}
