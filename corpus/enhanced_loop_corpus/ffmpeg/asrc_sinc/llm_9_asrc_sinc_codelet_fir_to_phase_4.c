#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < work_len / 4; i++) {
        work[i] *= 2;
        work[i + work_len / 4] *= 1.5f;
        work[i + work_len / 2] = 0;
        work[i + 3 * work_len / 4] = 0;
    }
}
