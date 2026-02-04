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
for (i = 0; i < 20; i += 2)
    lsf_q[i/2] = (lsf_r[i/2] * (1.0f / 32768.0f)) + lsf_no_r[i/2];
}
