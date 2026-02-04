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
    for (i = 0; i < width; i += 2) {
        if (i + 1 < width) {
            b1[i]     -= (5 * (b0[i]     + b2[i])     + 1) >> 2;
            b1[i + 1] -= (5 * (b0[i + 1] + b2[i + 1]) + 1) >> 2;
        } else {
            b1[i] -= (5 * (b0[i] + b2[i]) + 1) >> 2;
        }
    }
}
