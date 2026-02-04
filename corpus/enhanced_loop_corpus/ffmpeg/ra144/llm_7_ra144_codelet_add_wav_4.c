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
    int acc = 0;
    for (i = 0; i < 40; i++) {
        acc = (s1[i] * (unsigned int)v[0]) + s2[i] * v[1] + s3[i] * v[2];
        dest[i] = (int)(acc >> 12);
    }
}
