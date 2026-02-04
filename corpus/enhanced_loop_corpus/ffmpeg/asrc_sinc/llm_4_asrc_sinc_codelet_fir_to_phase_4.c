#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < work_len / 2; i++) {
        if (i % 2 == 0) {
            work[i] *= 2;
        } else {
            work[i] *= 1.5;
        }
        work[i + work_len / 2] = 0;
    }
}
