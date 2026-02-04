#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern IDWTELEM *b3;
extern IDWTELEM *b4;
extern IDWTELEM *b5;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i += 2) {
        for (int j = 0; j < 2 && (i + j) < width; j++) {
            int idx = i + j;
            b4[idx] -= (3 * (b3[idx] + b5[idx]) + 4) >> 3;
            b3[idx] -= (1 * (b2[idx] + b4[idx]) + 0) >> 0;
            b2[idx] += (1 * (b1[idx] + b3[idx]) + 4 * b2[idx] + 8) >> 4;
            b1[idx] += (3 * (b0[idx] + b2[idx]) + 0) >> 1;
        }
    }
}
