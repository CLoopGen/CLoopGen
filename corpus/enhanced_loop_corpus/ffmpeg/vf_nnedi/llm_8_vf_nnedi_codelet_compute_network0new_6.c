#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *data;
extern int16_t *ws;
extern float *wf;
extern float vals[8];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int sum1 = 0, sum2 = 0;
    float t1, t2;
    for (j = 0; j < 32; j++) {
        sum1 += data[j] * ws[(i << 2) + ((j >> 3) << 4) + (j & 7)];
        sum2 += data[j + 32] * ws[(i << 2) + (((j + 32) >> 3) << 4) + ((j + 32) & 7)];
    }
    t1 = sum1 * wf[i % 4] + wf[4 + (i % 4)];
    t2 = sum2 * wf[i % 4] + wf[4 + (i % 4)];
    vals[i % 4] += t1 / (1.F + (t1 >= 0 ? t1 : -t1));
    if (i < 4) vals[i + 4] = t2 / (1.F + (t2 >= 0 ? t2 : -t2));
}
}
