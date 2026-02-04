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
for (i = 0; i < n; i += 2) {
    int sum0 = 0, sum1 = 0;
    int off0 = ((i >> 2) << 3) + (i & 3);
    int off1 = (((i+1) >> 2) << 3) + ((i+1) & 3);
    for (j = 0; j < len; j++) {
        sum0 += data[j] * weights[i * len + j];
        if (i + 1 < n)
            sum1 += data[j] * weights[(i + 1) * len + j];
    }
    vals[i] = sum0 * wf[off0] * scale[0] + wf[off0 + 4];
    if (i + 1 < n)
        vals[i + 1] = sum1 * wf[off1] * scale[0] + wf[off1 + 4];
}
}
