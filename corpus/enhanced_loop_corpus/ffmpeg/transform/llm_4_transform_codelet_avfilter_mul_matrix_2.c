#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *m1;
extern float scalar;
extern float *result;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 9; i++) {
        if (!(i & 1)) {
            result[i] = m1[i] * scalar;
        } else {
            result[i] = 0.0f;
        }
    }
}
