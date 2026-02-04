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
int j, k;
for (j = 0; j < 4; j++) {
    for (k = 0; k < 10; k++) {
        int idx = j * 10 + k;
        dest[idx] = (s2[idx] * v[1] + s3[idx] * v[2]) >> 12;
    }
}
}
