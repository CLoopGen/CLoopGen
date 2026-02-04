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
    for (i = 0; i < width; i++) {
        b1[i] = ((unsigned int)(b1[i]) + ((int)(6497 * (b0[i] + (unsigned int)b2[i]) + 2048) >> 12));
        if (i % 2 == 0) {
            i += 1;
        }
    }
}
