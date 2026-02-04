#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *pIn;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128 / 2; i++) {
        float temp1 = pIn[i];
        float temp2 = pIn[128 - 1 - i];
        pIn[i] = temp2;
        pIn[128 - 1 - i] = temp1;
    }
}
