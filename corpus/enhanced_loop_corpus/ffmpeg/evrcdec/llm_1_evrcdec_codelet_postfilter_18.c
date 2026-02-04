#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int length;
extern float scratch[54];
extern float sum1;
extern float sum2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < length; i++) {
            if (j == 0) {
                sum1 += in[i] * in[i];
            } else {
                sum2 += scratch[i] * scratch[i];
            }
        }
    }
}
