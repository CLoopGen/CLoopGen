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
    for (i = 1; i < 40 - lag; i++)
        vect[lag + i] = cb[i - 1];
    if (40 - lag > 0)
        vect[lag] = cb[0];
}
