#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 1; j < work_len / 2; j++) {
        work[j] = work[j] * 2;
        work[j + work_len / 2] = work[j] / 2;
    }
}
