#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const float ff_pow_0_5[16];
extern float *iir_mem;
extern float *filt_mem[2];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    float temp1 = iir_mem[i] * ff_pow_0_5[i];
    float temp2 = iir_mem[i + 8] * ff_pow_0_5[i + 8];
    filt_mem[0][i] = temp1 + temp2;
    filt_mem[0][i + 8] = temp1 - temp2;
}
}
