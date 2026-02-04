#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    float temp;
    for (k = 1; k < work_len / 2; k++) {
        temp = work[k] * 2;
        work[k + work_len / 2] = 0;
        work[k] = temp;
    }
}
