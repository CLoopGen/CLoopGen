#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        unsigned int temp = (unsigned int)(b0[i] + b2[i] + 2);
        if (i % 2 == 0) {
            b1[i] -= (int)(temp >> 2);
        } else {
            b1[i] -= (int)(temp >> 1) & 0xFFFF;
        }
    }
}
