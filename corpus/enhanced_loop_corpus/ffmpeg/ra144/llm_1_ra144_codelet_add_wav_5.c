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
for (i = 0; i < 10; i++) {
    dest[i] = (s2[i] * v[1] + s3[i] * v[2]) >> 12;
    dest[i + 10] = (s2[i + 10] * v[1] + s3[i + 10] * v[2]) >> 12;
    dest[i + 20] = (s2[i + 20] * v[1] + s3[i + 20] * v[2]) >> 12;
    dest[i + 30] = (s2[i + 30] * v[1] + s3[i + 30] * v[2]) >> 12;
}
}
