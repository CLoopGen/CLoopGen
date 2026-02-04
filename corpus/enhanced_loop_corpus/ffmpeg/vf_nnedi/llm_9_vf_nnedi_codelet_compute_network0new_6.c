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
for (i = 0; i < 2; i++) {
    float acc[8] = {0};
    for (j = 0; j < 128; j += 2) {
        int idx1 = (j < 64) ? j : 0;
        int idx2 = (j+1 < 64) ? j+1 : 0;
        int base = (i << 3) + ((j >> 4) << 5);
        for (int k = 0; k < 4; k++) {
            acc[k] += data[idx1] * ws[base + k];
            acc[k + 4] += data[idx2] * ws[base + k + 4];
        }
    }
    for (int k = 0; k < 8; k++) {
        float t = acc[k] * wf[k % 4] + wf[4 + (k % 4)];
        vals[k % 4] = (vals[k % 4] + t) / (2.F + (t >= 0 ? t : -t));
    }
}
}
