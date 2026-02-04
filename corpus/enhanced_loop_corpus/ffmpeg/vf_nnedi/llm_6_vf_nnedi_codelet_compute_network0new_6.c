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
for (i = 0; i < 4; i++) {
    int sum = 0;
    float t;
    int offset_i = i << 3;
    for (j = 0; j < 64; j++) {
        int idx_ws = offset_i + ((j >> 3) << 5) + (j & 7);
        sum += data[j] * ws[idx_ws];
    }
    t = sum * wf[i] + wf[4 + i];
    float abs_t = t >= 0 ? t : -t;
    vals[i] = t / (1.F + abs_t);
}

}
