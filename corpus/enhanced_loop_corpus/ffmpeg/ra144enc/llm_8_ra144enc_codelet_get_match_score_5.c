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
    for (i = 0; i < 80; i += 2) {
        float w = work[i];
        g += w * w;
        c += data[i] * w;
        if (i + 1 < 40) {
            w = work[i + 1];
            g += w * w;
            c += data[i + 1] * w;
        }
    }
}
