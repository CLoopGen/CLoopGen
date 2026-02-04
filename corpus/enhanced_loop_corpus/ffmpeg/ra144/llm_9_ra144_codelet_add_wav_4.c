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
for (i = 0; i < 20; i++) {
    int val1 = (s1[i] * v[0]) >> 12;
    int val2 = (s2[i] * v[1]) >> 12;
    dest[i] = val1 + val2;
    dest[i + 20] = (int)((s1[i + 20] * (unsigned int)v[0] + s3[i] * v[2]) >> 12);
}
}
