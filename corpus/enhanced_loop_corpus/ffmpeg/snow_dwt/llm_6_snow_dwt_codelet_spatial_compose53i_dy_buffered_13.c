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
    IDWTELEM temp1 = b1[x];
    IDWTELEM temp3 = b3[x];
    b2[x] -= (temp1 + temp3 + 2) >> 2;
    IDWTELEM temp0 = b0[x];
    IDWTELEM temp2 = b2[x];
    b1[x] += (temp0 + temp2) >> 1;
}
}
