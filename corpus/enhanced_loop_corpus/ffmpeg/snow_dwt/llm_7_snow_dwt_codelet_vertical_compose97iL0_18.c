#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width > 0) {
        b1[0] += (1 * (b0[0] + b2[0]) + 4 * b1[0] + 8) >> 4;
        for (i = 1; i < width; i++) {
            b1[i] += (1 * (b0[i-1] + b2[i-1]) + 4 * b1[i] + 8) >> 4;
        }
    }
}
