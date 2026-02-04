#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *pIn;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        int index1 = i;
        int index2 = 128 - 1 - i;
        float val1 = pIn[index1];
        float val2 = pIn[index2];
        pIn[index1] = val2;
        pIn[index2] = val1;
    }
}
