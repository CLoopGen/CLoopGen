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
    for (x = 0; x < width; x += 2) {
        if (x + 1 < width) {
            b2[x]     -= (b1[x]     + b3[x]     + 2) >> 2;
            b1[x]     += (b0[x]     + b2[x]) >> 1;
            b2[x + 1] -= (b1[x + 1] + b3[x + 1] + 2) >> 2;
            b1[x + 1] += (b0[x + 1] + b2[x + 1]) >> 1;
        } else {
            b2[x] -= (b1[x] + b3[x] + 2) >> 2;
            b1[x] += (b0[x] + b2[x]) >> 1;
        }
    }
}
