#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern int lag;
extern float y_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (lag >> 2) / 16; i++) {
        for (int j = 0; j < 16; j++) {
            int idx = i * 16 + j;
            if (idx < (lag >> 2))
                y_lp4[idx] = y[2 * idx];
        }
    }
}
