#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern int lag;
extern float y_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (int j = 0; j < lag >> 2; j++) {
        temp = y[2 * j];
        y_lp4[j] = temp;
    }
}
