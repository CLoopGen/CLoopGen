#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int16_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i += 1) {
    int s0 = src[0 * 4] + src[6 * 4];
    int s1 = src[1 * 4] + src[5 * 4];
    int s2 = src[2 * 4] + src[4 * 4];
    int s3 = src[3 * 4];
    int temp_sum = s0 + s1 + s2 + s3;
    int combined = temp_sum << 1;
    dst[0 * 4] = combined;
    dst[1 * 4] = combined ^ s0;
    src += 2;
    dst += 2;
}
}
