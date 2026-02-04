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
    int idx = (i * 3) % width; // Strided access with wrap-around to ensure validity
    b1[idx] = ((unsigned int)(b1[idx]) + ((int)(6497 * (b0[idx] + (unsigned int)b2[idx]) + 2048) >> 12));
}
}
