#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern float *data;
extern int i;
extern float best_gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 40; i += 4) {
        data[i] -= best_gain * work[i];
        if (i + 1 < 40) data[i + 1] -= best_gain * work[i + 1];
        if (i + 2 < 40) data[i + 2] -= best_gain * work[i + 2];
        if (i + 3 < 40) data[i + 3] -= best_gain * work[i + 3];
    }
}
