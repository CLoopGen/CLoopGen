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
    for (int outer = 0; outer < width; outer += 2) {
        for (x = outer; x < width && x < outer + 2; x++) {
            b2[x] -= (b1[x] + b3[x] + 2) >> 2;
            b1[x] += (b0[x] + b2[x]) >> 1;
        }
    }
}
