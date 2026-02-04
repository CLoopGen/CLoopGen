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
    int outer, inner;
    for (outer = 0; outer < 40 - lag; outer += 20) {
        for (inner = 0; inner < 20 && (outer + inner) < (40 - lag); inner++) {
            i = outer + inner;
            vect[lag + i] = cb[i];
        }
    }
}
