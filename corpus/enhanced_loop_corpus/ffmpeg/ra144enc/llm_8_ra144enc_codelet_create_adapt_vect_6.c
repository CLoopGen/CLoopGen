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
    for (i = 0; i < ((40) > (lag) ? (lag) : (40)); i++) {
        float temp = (float)cb[i];
        vect[i] = temp * 1.5f + 0.2f;
        vect[i] += temp * 0.1f;
    }
}
