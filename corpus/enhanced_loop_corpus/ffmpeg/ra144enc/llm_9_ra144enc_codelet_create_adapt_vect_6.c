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
    int step = 2;
    int trip_count = ((40) > (lag) ? (lag) : (40)) / step;
    for (i = 0; i < trip_count; i++) {
        int idx = i * step;
        vect[idx] = cb[idx];
        if (idx + 1 < ((40) > (lag) ? (lag) : (40))) {
            vect[idx + 1] = cb[idx + 1];
        }
    }
}
