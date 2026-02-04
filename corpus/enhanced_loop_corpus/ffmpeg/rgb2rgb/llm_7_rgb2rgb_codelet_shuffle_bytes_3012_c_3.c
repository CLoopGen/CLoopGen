#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size - 3; i += 4) {
        dst[i + 3] = src[i + 2];
        dst[i + 2] = src[i + 1];
        dst[i + 1] = src[i + 0];
        dst[i + 0] = src[i + 3];
    }
    // Handle remaining elements if any (cleanup loop), but maintain i as loop index
    while (i < src_size) {
        dst[i] = src[i];
        i++;
    }
}
