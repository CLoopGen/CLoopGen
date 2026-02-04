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
    int outer_i;
    for (outer_i = 0; outer_i < width; outer_i += 16) {
        for (i = outer_i; i < width && i < outer_i + 16; i++)
            b1[i] -= (b0[i] + b2[i] + 2) >> 2;
    }
}
