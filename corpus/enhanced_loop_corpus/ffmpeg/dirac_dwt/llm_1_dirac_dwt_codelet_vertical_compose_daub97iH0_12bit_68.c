#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 2; j++) {
    for (i = j; i < width; i += 2) {
        b1[i] = ((unsigned int)(b1[i]) + ((int)(6497 * (b0[i] + (unsigned int)b2[i]) + 2048) >> 12));
    }
}
}
