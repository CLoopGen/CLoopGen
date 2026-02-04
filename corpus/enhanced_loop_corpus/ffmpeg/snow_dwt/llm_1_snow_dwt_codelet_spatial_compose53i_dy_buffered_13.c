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
    if (width > 0) {
        x = 0;
        for (int phase = 0; phase < 2; phase++) {
            for (; x < width; x++) {
                if (phase == 0) {
                    b2[x] -= (b1[x] + b3[x] + 2) >> 2;
                } else {
                    b1[x] += (b0[x] + b2[x]) >> 1;
                }
            }
            x = 0; // Reset for second phase
        }
    }
}
