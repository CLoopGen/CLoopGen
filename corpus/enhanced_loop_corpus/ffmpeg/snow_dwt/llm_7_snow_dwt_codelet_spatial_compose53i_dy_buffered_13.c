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
IDWTELEM prev_b2 = 0;
for (x = 0; x < width; x++) {
    IDWTELEM current_b2 = b2[x];
    b2[x] -= (b1[x] + b3[x] + 2) >> 2;
    b1[x] += (b0[x] + prev_b2) >> 1;
    prev_b2 = current_b2;
}
}
