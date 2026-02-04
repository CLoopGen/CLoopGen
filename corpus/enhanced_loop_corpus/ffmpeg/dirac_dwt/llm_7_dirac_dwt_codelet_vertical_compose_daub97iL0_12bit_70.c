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
    int32_t prev = 0;
    for (i = 0; i < width; i++) {
        int32_t current_b0 = b0[i];
        int32_t current_b2 = b2[i];
        int32_t sum = (unsigned int)(current_b0) + (unsigned int)(current_b2);
        int32_t result = ((unsigned int)(b1[i]) + ((int)(217 * sum + 2048) >> 12));
        b1[i] = result + prev;
        prev = result & 0xFFFF;
    }
}
