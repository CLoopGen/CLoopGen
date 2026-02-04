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
        int upper = (outer_i + 16 < width) ? outer_i + 16 : width;
        for (i = outer_i; i < upper; i++)
            b1[i] += (1 * (b0[i] + b2[i]) + 4 * b1[i] + 8) >> 4;
    }
}
