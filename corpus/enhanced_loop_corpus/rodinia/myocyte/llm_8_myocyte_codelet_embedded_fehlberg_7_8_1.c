#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float *initvalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 182; i += 2) {
        initvalu_temp[i] = initvalu[i];
        if (i + 1 < 91) {
            initvalu_temp[i + 1] = initvalu[i + 1];
        }
    }
}
