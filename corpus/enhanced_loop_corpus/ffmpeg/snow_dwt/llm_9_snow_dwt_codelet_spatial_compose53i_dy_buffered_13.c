#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int width;
extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern IDWTELEM *b3;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < width; x++) {
        IDWTELEM temp1 = (b1[x] + b3[x] + 2) >> 2;
        IDWTELEM temp2 = (b0[x] + b2[x] + 1) >> 1;
        b2[x] -= temp1;
        b1[x] += temp2;
        b0[x] += (temp1 + temp2) >> 2;
        b3[x] -= (temp1 - temp2) >> 3;
    }
}
