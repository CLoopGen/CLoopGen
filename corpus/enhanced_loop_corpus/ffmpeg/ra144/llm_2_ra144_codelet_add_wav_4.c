#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dest;
extern  int16_t *s1;
extern  int8_t *s2;
extern  int8_t *s3;
extern int i;
extern int v[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every other element)
    // This changes the access pattern to non-consecutive, reducing spatial locality
    for (i = 0; i < 80; i += 2) {
        int idx = i / 2;
        if (idx >= 40) break;
        dest[idx] = (int)((s1[i] * (unsigned int)v[0]) + s2[i] * v[1] + s3[i] * v[2]) >> 12;
    }
}
