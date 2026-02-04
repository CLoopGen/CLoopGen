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
    for (j = 0; j < width; j += 2) {
        if (j + 1 < width) {
            b1[j]   += (1 * (b0[j]   + b2[j])   + 0) >> 0;
            b1[j+1] += (1 * (b0[j+1] + b2[j+1]) + 0) >> 0;
        } else {
            b1[j] += (1 * (b0[j] + b2[j]) + 0) >> 0;
        }
    }
}
