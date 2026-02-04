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
    for (i = 0; i < 40; ++i) {
        if ((s2[i] | s3[i]) != 0) {
            dest[i] = (s2[i] * v[1] + s3[i] * v[2]) >> 12;
        } else {
            dest[i] = 0;
        }
    }
}
