#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in;
extern  float zero_coeffs[2];
extern  float pole_coeffs[2];
extern float gain;
extern float mem[2];
extern int n;
extern int i;
extern float tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *indices = (int*)alloca(n * sizeof(int));
for (int j = 0; j < n; j++) {
    indices[j] = j;
}
for (i = 0; i < n; i++) {
    int idx = indices[i]; 
    tmp = gain * in[idx] - pole_coeffs[0] * mem[0] - pole_coeffs[1] * mem[1];
    out[idx] = tmp + zero_coeffs[0] * mem[0] + zero_coeffs[1] * mem[1];
    mem[1] = mem[0];
    mem[0] = tmp;
}
}
