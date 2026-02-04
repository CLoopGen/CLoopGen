#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float lsf_no_r[10];
extern int16_t lsf_r[10];
extern float lsf_q[10];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float acc = 0.0f;
    for (i = 0; i < 10; i++) {
        acc += lsf_r[i] * ((8000. / 32768.) / 8000.);
        lsf_q[i] = acc + lsf_no_r[i] * (1. / 8000.);
    }
}
