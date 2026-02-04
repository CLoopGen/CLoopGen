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
for (i = 0; i < 16; i++)
    filt_mem[0][i] = iir_mem[i] * ff_pow_0_5[i];

}
