#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < work_len / 2; i += 2) {
        work[i] *= 2;
        work[i] += 1.5f;
        work[i - 1] *= 0.5f;
        work[i + work_len / 2] = 0;
        work[i + work_len / 2 + 1] = 0;
    }
}
