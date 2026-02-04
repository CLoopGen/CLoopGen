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
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < width; i++) {
            b4[i] -= (3 * (b3[i] + b5[i]) + 4) >> 3;
            b3[i] -= (1 * (b2[i] + b4[i]) + 0) >> 0;
            b2[i] += (1 * (b1[i] + b3[i]) + 4 * b2[i] + 8) >> 4;
            b1[i] += (3 * (b0[i] + b2[i]) + 0) >> 1;
        }
    }
}
