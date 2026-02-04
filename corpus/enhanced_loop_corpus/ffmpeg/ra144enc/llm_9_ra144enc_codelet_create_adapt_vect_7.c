#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *vect;
extern  int16_t *cb;
extern int lag;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset;
    for (i = 0; i < 80 - (lag << 1); i++) {
        offset = lag + (i >> 1);
        vect[offset] = (float)(cb[offset] * 2);
    }
}
