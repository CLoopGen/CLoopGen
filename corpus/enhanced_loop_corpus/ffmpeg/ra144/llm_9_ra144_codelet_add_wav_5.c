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
    for (i = 0; i < 20; i++) {
        int16_t temp1 = (s2[2*i] * v[1] + s3[2*i] * v[2]) >> 12;
        int16_t temp2 = (s2[2*i + 1] * v[1] + s3[2*i + 1] * v[2]) >> 12;
        dest[2*i] = temp1;
        dest[2*i + 1] = temp2;
    }
}
