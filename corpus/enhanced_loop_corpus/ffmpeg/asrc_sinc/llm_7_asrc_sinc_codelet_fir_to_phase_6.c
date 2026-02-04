#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float acc = 0.0F;
    float factor = 2.F / work_len;
    for (i = 0; i < work_len; i++) {
        acc += work[i];
        work[i] = acc * factor;
    }
}
