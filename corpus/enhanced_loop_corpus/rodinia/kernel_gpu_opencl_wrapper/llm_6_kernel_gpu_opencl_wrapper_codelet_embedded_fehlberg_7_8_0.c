#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float *initvalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_val;
    for (i = 0; i < 91; i++) {
        temp_val = initvalu[i];
        initvalu_temp[i] = temp_val;
    }
}
