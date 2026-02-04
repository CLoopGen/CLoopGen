#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern  float *data;
extern float c;
extern float g;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (process array from end to start)
    for (i = 39; i >= 0; i--) {
        g += work[i] * work[i];
        c += data[i] * work[i];
    }
}
