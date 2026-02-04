#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern IDWTELEM *b3;
extern IDWTELEM *b4;
extern IDWTELEM *b5;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2)
    // Processes every second element in reverse order to alter spatial locality
    for (i = width - 1; i >= 0; i -= 2) {
        b4[i] -= (3 * (b3[i] + b5[i]) + 4) >> 3;
        b3[i] -= (1 * (b2[i] + b4[i]) + 0) >> 0;
        b2[i] += (1 * (b1[i] + b3[i]) + 4 * b2[i] + 8) >> 4;
        b1[i] += (3 * (b0[i] + b2[i]) + 0) >> 1;
    }
    // Handle odd-sized width by processing the first element if needed
    if (width > 0 && (width % 2 == 1)) {
        i = 0;
        b4[i] -= (3 * (b3[i] + b5[i]) + 4) >> 3;
        b3[i] -= (1 * (b2[i] + b4[i]) + 0) >> 0;
        b2[i] += (1 * (b1[i] + b3[i]) + 4 * b2[i] + 8) >> 4;
        b1[i] += (3 * (b0[i] + b2[i]) + 0) >> 1;
    }
}
