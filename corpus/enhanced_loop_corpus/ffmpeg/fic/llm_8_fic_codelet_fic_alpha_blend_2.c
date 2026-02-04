#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern uint8_t *alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            dst[i] += ((src[i] - dst[i]) * alpha[i]) >> 8;
            dst[i+1] += ((src[i+1] - dst[i+1]) * alpha[i+1]) >> 8;
        } else {
            dst[i] += ((src[i] - dst[i]) * alpha[i]) >> 8;
        }
    }
}
