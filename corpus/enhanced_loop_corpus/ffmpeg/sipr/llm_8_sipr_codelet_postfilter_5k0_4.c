#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const float ff_pow_0_75[10];
extern const float ff_pow_0_5[16];
extern  float *lpc;
extern float lpc_n[10];
extern float lpc_d[10];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 10; i++) {
    lpc_d[i] = lpc[i] * ff_pow_0_75[i] + ff_pow_0_5[i] * 0.5f;
    lpc_n[i] = lpc[i] * ff_pow_0_5[i] - ff_pow_0_75[i] * 0.25f;
}
}
