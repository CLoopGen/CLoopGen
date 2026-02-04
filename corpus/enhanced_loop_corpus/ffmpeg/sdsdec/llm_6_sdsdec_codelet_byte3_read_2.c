#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int sample0, sample1, sample2;
    for (i = 0; i < 120; i += 3) {
        sample0 = (unsigned int)src[i + 0] << 25;
        sample1 = (unsigned int)src[i + 1] << 18;
        sample2 = (unsigned int)src[i + 2] << 11;
        dst[i / 3] = sample0 | sample1 | sample2;
    }
}
