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
    float temp;
    for (i = 0; i < 40 - lag; i++) {
        temp = cb[i];
        vect[lag + i] = temp;
    }
}
