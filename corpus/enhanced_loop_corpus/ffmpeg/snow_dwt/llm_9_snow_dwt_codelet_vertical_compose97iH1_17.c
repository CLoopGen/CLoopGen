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
    int j;
    for (i = 0; i < width; i++) {
        IDWTELEM temp0 = b0[i];
        IDWTELEM temp2 = b2[i];
        IDWTELEM sum = temp0 + temp2;
        IDWTELEM avg = (sum + 1) >> 1;
        b1[i] -= avg;
        b1[i] -= avg;
    }
}
