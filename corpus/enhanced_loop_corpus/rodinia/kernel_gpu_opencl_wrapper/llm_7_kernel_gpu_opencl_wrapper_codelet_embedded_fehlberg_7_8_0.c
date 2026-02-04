#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float *initvalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 91; i++) {
        initvalu_temp[i] = initvalu[i-1];
    }
    if (91 > 0) {
        initvalu_temp[0] = initvalu[0];
    }
}
