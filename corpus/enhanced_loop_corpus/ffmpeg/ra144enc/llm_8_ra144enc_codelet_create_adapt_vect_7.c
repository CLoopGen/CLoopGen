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
    int j;
    for (i = 0; i < 40 - lag; i += 2) {
        vect[lag + i] = cb[i];
        if (i + 1 < 40 - lag)
            vect[lag + i + 1] = cb[i + 1];
    }
}
