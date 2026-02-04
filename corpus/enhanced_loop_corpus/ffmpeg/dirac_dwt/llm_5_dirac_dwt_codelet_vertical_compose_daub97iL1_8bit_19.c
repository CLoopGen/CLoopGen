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
        unsigned int sum = (unsigned int)(b0[i]) + (unsigned int)(b2[i]);
        int temp = (1817 * sum + 2048) >> 12;
        if (temp < (int)b1[i]) {
            b1[i] = (int16_t)(((unsigned int)(b1[i]) - temp));
        } else {
            b1[i] = 0;
        }
    }
}
