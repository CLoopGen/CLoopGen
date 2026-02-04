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
int sum[4] = {0};
float t;
for (j = 0; j < 64; j++) {
    for (i = 0; i < 4; i++) {
        sum[i] += data[j] * ws[(i << 3) + ((j >> 3) << 5) + (j & 7)];
    }
}
for (i = 0; i < 4; i++) {
    t = sum[i] * wf[i] + wf[4 + i];
    vals[i] = t / (1.F + (t >= 0 ? t : -t));
}
}
