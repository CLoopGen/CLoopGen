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
    for (int j = 0; j < 2; j++)
        for (i = j * 20; i < (j + 1) * 20 && i < 40; i++)
            dest[i] = (int)((s1[i] * (unsigned int)v[0]) + s2[i] * v[1] + s3[i] * v[2]) >> 12;
}
