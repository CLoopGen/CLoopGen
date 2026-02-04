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
    for (i = 0; i < 40; i++) {
        temp_g += work[i] * work[i];
        temp_c += data[i] * work[i];
    }
    g += temp_g;
    c += temp_c;
}
