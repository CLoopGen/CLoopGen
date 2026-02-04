#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dest;
extern  int8_t *s2;
extern  int8_t *s3;
extern int i;
extern int v[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    // Process only even indices: 0, 2, 4, ..., 38 (20 iterations effectively)
    for (i = 0; i < 40; i += 2)
        dest[i] = (s2[i] * v[1] + s3[i] * v[2]) >> 12;
}
