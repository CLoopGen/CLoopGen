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
    for (i = 0; i < width; i++) {
        DWTELEM sum0 = b0[i];
        DWTELEM sum2 = b2[i];
        for (j = 0; j < 3; j++) {
            sum0 += b0[i] >> j;
            sum2 += b2[i] >> j;
        }
        b1[i] += (sum0 + sum2) >> 1;
    }
}
