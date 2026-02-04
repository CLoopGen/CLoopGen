#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern int i;
extern int work_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from middle toward start
    for (i = (work_len / 2) - 1; i >= 1; i--) {
        work[i] *= 2;
        work[i + work_len / 2] = 0;
    }
}
