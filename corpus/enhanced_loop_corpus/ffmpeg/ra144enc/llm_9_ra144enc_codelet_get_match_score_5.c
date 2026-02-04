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
    float temp_g = 0.0f;
    float temp_c = 0.0f;
    for (i = 0; i < 20; i++) {
        float w0 = work[i];
        float w1 = work[i + 20];
        temp_g += w0 * w0 + w1 * w1;
        temp_c += data[i] * w0 + data[i + 20] * w1;
    }
    g += temp_g;
    c += temp_c;
}
