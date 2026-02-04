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
for (i = 0; i < 5; i++) {
    int j = 2 * i;
    lpc_d[j] = lpc[j] * ff_pow_0_75[j];
    lpc_n[j] = lpc[j] * ff_pow_0_5[j];
    if (j + 1 < 10) {
        lpc_d[j + 1] = lpc[j + 1] * ff_pow_0_75[j + 1];
        lpc_n[j + 1] = lpc[j + 1] * ff_pow_0_5[j + 1];
    }
}
}
