#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern int len;
extern float Syy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < len; j += 2) {
        if (j + 1 < len) {
            Syy += y[j] * y[j] + y[j+1] * y[j+1];
        } else {
            Syy += y[j] * y[j];
        }
    }
}
