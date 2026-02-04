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
    for (i = 0; i < 40; i += 2) {
        g += work[i] * work[i];
        c += data[i] * work[i];
        if (i + 1 < 40) {
            g += work[i+1] * work[i+1];
            c += data[i+1] * work[i+1];
        }
    }
}
