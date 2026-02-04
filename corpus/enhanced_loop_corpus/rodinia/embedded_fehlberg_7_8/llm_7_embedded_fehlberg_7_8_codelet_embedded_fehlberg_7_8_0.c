#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float *initvalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 90; i++) {
        initvalu_temp[i + 1] = initvalu[i];
    }
    if (i == 90) {
        initvalu_temp[0] = initvalu[90];
    }
}
