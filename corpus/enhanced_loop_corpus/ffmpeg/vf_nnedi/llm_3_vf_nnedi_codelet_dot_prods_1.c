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
for (i = 0; i < n; i++) {
    int sum = 0, off = ((i >> 2) << 3) + (i & 3);
    int idx = i * len;
    for (j = 0; j < len; j++) {
        int access_idx = j;
        sum += data[access_idx] * weights[idx + j];
    }
    vals[i] = sum * wf[off] * scale[0] + wf[off + 4];
}
}
