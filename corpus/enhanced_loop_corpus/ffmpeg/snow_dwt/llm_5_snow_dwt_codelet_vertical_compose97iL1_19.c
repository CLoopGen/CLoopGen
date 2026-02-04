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
    for (i = 0; i < width; i++) {
        IDWTELEM sum = b0[i] + b2[i];
        int offset = (3 * sum + 4) >> 3;
        if (i % 2 == 0)
            b1[i] -= offset;
    }
}
