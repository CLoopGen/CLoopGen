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
    int limit = (40 > lag) ? 40 : lag;
    for (i = 0; i < limit; i++) {
        vect[i] = cb[i];
        if (i >= 39) break;
    }
}
