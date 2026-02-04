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
    int step = 1;
    for (outer_i = 0; outer_i < width; outer_i += step)
        for (i = outer_i; i < outer_i + step && i < width; i++)
            b1[i] += (3 * (b0[i] + b2[i]) + 4) >> 3;
}
