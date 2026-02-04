#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        int temp = b1[i];
        if (i % 2 == 0) {
            b0[i] = b0[i] - ((unsigned int)(temp + 1U) >> 1);
        } else {
            b0[i] = b0[i] - ((unsigned int)(temp + 3U) >> 1);
        }
        b1[i] = temp + b0[i];
    }
}
