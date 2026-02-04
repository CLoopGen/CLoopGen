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
    // Variant 2: Reverse consecutive memory access – traverse arrays from end to start
    for (i = 39; i >= 0; i--)
        dest[i] = (s2[i] * v[1] + s3[i] * v[2]) >> 12;
}
