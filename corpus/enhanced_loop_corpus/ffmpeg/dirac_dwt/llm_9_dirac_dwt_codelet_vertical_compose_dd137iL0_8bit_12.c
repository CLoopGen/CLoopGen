#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;
extern int16_t *b3;
extern int16_t *b4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        int temp1 = 9U * (b1[i] + b3[i]);
        int temp2 = b0[i] + b4[i];
        int adjusted = (temp1 - temp2 + 8) >> 4;
        b2[i] = (int)((unsigned int)(b2[i]) - adjusted);
        b2[i] = (int)((unsigned int)(b2[i]) + ((b1[i] - b3[i]) >> 3));
    }
}
