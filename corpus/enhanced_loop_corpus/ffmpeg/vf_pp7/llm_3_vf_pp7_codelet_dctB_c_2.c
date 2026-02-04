#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int16_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int offsets[] = {0, 4, 8, 12};
for (i = 0; i < 4; i++) {
    int base_src = i * 4;
    int base_dst = i * 4;
    int s0 = src[base_src + offsets[0]] + src[base_src + offsets[6]];
    int s1 = src[base_src + offsets[1]] + src[base_src + offsets[5]];
    int s2 = src[base_src + offsets[2]] + src[base_src + offsets[4]];
    int s3 = src[base_src + offsets[3]];
    int s = s3 + s3;
    s3 = s - s0;
    s0 = s + s0;
    s = s2 + s1;
    s2 = s2 - s1;
    dst[base_dst + offsets[0]] = s0 + s;
    dst[base_dst + offsets[2]] = s0 - s;
    dst[base_dst + offsets[1]] = 2 * s3 + s2;
    dst[base_dst + offsets[3]] = s3 - 2 * s2;
}
}
