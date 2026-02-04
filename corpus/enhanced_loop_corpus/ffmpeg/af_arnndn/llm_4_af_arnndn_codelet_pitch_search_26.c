#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern int lag;
extern float y_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < (lag >> 2); j++) {
        if (j % 2 == 0) {
            y_lp4[j] = y[2 * j];
        } else {
            y_lp4[j] = 0.0f;
        }
    }
}
