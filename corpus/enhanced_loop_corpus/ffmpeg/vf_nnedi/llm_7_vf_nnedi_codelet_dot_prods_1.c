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
    int sum1 = 0, sum2 = 0;
    int off = ((i >> 2) << 3) + (i & 3);
    for (j = 0; j < len - (len % 2); j += 2) {
        sum1 += data[j]     * weights[i * len + j];
        sum2 += data[j + 1] * weights[i * len + j + 1];
    }
    for (; j < len; j++) {
        sum1 += data[j] * weights[i * len + j];
    }
    int sum = sum1 + sum2;
    vals[i] = sum * wf[off] * scale[0] + wf[off + 4];
}
}
