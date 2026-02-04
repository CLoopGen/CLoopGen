#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float factor = (work_len > 0) ? (2.F / work_len) : 0.F;
    for (i = 0; i < work_len; i += 2) {
        work[i] *= factor;
        if (i + 1 < work_len) {
            work[i + 1] *= factor;
        }
    }
}
