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
    for (i = 0; i < width; i += 2) {
        if (i + 1 < width) {
            b1[i]     += (b0[i] + b2[i]) >> 1;
            b1[i + 1] += (b0[i + 1] + b2[i + 1]) >> 1;
        } else {
            b1[i] += (b0[i] + b2[i]) >> 1;
        }
    }
}
