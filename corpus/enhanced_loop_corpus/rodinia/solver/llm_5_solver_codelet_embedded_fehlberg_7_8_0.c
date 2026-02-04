#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float *initvalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 91; i++) {
        if (initvalu[i] >= 0.0f) {
            initvalu_temp[i] = initvalu[i];
        } else {
            initvalu_temp[i] = 0.0f;
        }
    }
}
