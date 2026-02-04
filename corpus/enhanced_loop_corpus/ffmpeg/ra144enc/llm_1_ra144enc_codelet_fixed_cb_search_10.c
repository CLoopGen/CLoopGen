#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern float *data;
extern int i;
extern float gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 40; i += 4) {
        data[i]     -= gain * work[i];
        if (i + 1 < 40) data[i + 1] -= gain * work[i + 1];
        if (i + 2 < 40) data[i + 2] -= gain * work[i + 2];
        if (i + 3 < 40) data[i + 3] -= gain * work[i + 3];
    }
}
