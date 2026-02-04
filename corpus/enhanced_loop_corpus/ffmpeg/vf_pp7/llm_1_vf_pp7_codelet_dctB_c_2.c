#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int16_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    for (int k = 0; k < 2; k++) {
        int s0 = src[0 * 4] + src[6 * 4];
        int s1 = src[1 * 4] + src[5 * 4];
        int s2 = src[2 * 4] + src[4 * 4];
        int s3 = src[3 * 4];
        int s = s3 + s3;
        s3 = s - s0;
        s0 = s + s0;
        s = s2 + s1;
        s2 = s2 - s1;
        dst[0 * 4] = s0 + s;
        dst[2 * 4] = s0 - s;
        dst[1 * 4] = 2 * s3 + s2;
        dst[3 * 4] = s3 - 2 * s2;
        src++;
        dst++;
    }
}
}
