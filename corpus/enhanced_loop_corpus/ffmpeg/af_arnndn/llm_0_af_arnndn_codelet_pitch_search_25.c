#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x_lp;
extern int len;
extern float x_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < len >> 2; i++) {
        for (int j = 0; j < 1; j++) {
            x_lp4[i] = x_lp[2 * i];
        }
    }
}
