#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern float diff_mean;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_mean = diff_mean;
    for (i = 2; i < 14; i++) {
        local_mean = (local_mean + diff_isf[i]) * 0.5F;
    }
    diff_mean = local_mean;
}
