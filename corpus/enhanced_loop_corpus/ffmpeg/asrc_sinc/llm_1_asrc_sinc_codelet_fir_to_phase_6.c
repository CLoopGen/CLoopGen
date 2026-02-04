#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < work_len && work_len > 0; i++) {
        if (i % 2 == 0) {
            work[i] *= 2.F / work_len;
        } else {
            work[i] *= 2.F / work_len;
        }
    }
}
