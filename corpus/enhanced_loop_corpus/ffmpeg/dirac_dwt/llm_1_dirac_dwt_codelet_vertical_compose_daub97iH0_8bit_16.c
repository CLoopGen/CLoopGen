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
    for (int j = 0; j < 1; j++) {
        b1[i] = ((unsigned int)(b1[i]) + ((int)(6497 * (b0[i] + (unsigned int)b2[i]) + 2048) >> 12));
    }
}
}
