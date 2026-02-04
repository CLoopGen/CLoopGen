#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *vals;
extern  int n;
extern  int len;
extern  float *scale;
extern  int16_t *data;
extern  int16_t *weights;
extern  float *wf;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float temp_scale = scale[0];
for (i = 0; i < n; i++) {
    int sum = 0;
    int off = ((i >> 2) << 3) + (i & 3);
    float wfv = wf[off], wfv4 = wf[off + 4];
    for (j = 0; j < len; j++) {
        sum += data[j] * weights[i * len + j];
    }
    vals[i] = sum * wfv * temp_scale + wfv4;
}
}
