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
    lpc_d[0] = lpc[0] * ff_pow_0_75[0];
    lpc_n[0] = lpc[0] * ff_pow_0_5[0];
    for (i = 1; i < 10; i++) {
        lpc_d[i] = lpc[i] * ff_pow_0_75[i] + lpc_d[i-1] * 0.1f;
        lpc_n[i] = lpc[i] * ff_pow_0_5[i] + lpc_n[i-1] * 0.1f;
    }
}
