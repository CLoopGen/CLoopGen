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
float scale1 = 1.0f / 32768.0f;
float scale2 = 1.0f / 8000.0f;
for (i = 0; i < 5; i++) {
    lsf_q[i]           = lsf_r[i] * scale1 * scale2 + lsf_no_r[i] * scale2;
    lsf_q[i + 5]       = lsf_r[i + 5] * scale1 * scale2 + lsf_no_r[i + 5] * scale2;
}
}
