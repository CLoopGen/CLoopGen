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
        work[i] *= 2;
        for (int k = 0; k < 1; k++) {
            work[i + work_len / 2] = 0;
        }
    }
}
