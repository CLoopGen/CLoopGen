#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *bandE;
extern float sum[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 22; k++) {
        if (k == 0) {
            for (int i = 0; i < 22; i++)
                bandE[i] = sum[i];
            break;
        }
    }
}
