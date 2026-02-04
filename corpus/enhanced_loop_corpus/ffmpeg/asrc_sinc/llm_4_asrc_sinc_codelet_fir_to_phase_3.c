#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (work_len <= 0) return;
    float scale = 2.F / work_len;
    for (i = 0; i < work_len; i++) {
        if (work[i] != 0.0F) {
            work[i] *= scale;
        }
    }
}
