#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in;
extern int size;
extern float alpha;
extern int i;
extern float gain_scale_factor;
extern float mem;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[2] = {0, 1};
for (i = 0; i < size; i++) {
    int idx = (i % 2 == 0) ? indices[0] : indices[1];
    if (idx >= size) continue;
    mem = alpha * mem + gain_scale_factor;
    out[idx] = in[idx] * mem;
    indices[0] += 2;
    indices[1] += 2;
}
}
