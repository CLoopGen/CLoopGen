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
for (i = 0; i < 80; i += 2) {
    int temp1 = s1[i] * (unsigned int)v[0];
    int temp2 = s2[i] * v[1];
    int temp3 = s3[i] * v[2];
    dest[i] = (int)((temp1 + temp2 + temp3) >> 12);
    if (i + 1 < 80) {
        temp1 = s1[i+1] * (unsigned int)v[0];
        temp2 = s2[i+1] * v[1];
        temp3 = s3[i+1] * v[2];
        dest[i+1] = (int)((temp1 + temp2 + temp3) >> 12);
    }
}
}
