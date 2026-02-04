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
    for (i = 0; i < 80; i += 2) {
        dest[i] = (s2[i] * v[1] + s3[i] * v[2]) >> 12;
        if (i + 1 < 40) {
            dest[i + 1] = (s2[i + 1] * v[1] + s3[i + 1] * v[2]) >> 12;
        }
    }
}
