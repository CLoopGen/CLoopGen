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
    int stride = 4;
    for (i = 0; i < width; i += stride) {
        for (int j = 0; j < stride && (i + j) < width; j++) {
            b1[i + j] += (b0[i + j] + b2[i + j]) >> 1;
        }
    }
}
