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
    int16_t temp;
    for (i = 0; i < 40; i++) {
        temp = (int16_t)((s1[i] * (unsigned int)v[0]) >> 12);
        dest[i] = (int)(temp + ((s2[i] * v[1]) >> 12) + ((s3[i] * v[2]) >> 12));
    }
}
