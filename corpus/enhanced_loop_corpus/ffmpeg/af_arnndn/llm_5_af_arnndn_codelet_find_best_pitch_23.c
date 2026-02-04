#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern int len;
extern float Syy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < len; j++) {
        if (y[j] != 0.0f) {
            Syy += y[j] * y[j];
        }
    }
}
