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
    for (i = 0; i < work_len; i++) {
        float factor = 2.F / work_len;
        for (j = 0; j < 4; j++) {
            work[i] *= factor;
        }
    }
}
