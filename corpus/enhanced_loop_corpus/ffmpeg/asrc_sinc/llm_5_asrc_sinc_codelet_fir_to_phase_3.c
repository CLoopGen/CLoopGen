#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float scale = (work_len > 0) ? (2.F / work_len) : 0.F;
    for (i = 0; i < work_len; i++) {
        if (i % 2 == 0) {
            work[i] *= scale;
        } else {
            work[i] += scale;
        }
    }
}
