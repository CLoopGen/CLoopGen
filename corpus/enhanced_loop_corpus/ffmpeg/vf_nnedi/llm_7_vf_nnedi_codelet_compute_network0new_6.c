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
float temp_vals[4];
for (i = 0; i < 4; i++) {
    int sum = 0;
    for (j = 0; j < 64; j++) {
        int coeff_idx = (i << 3) + ((j >> 3) << 5) + (j & 7);
        sum += data[j] * ws[coeff_idx];
    }
    float t = sum * wf[i] + wf[4 + i];
    temp_vals[i] = t;
}
for (i = 0; i < 4; i++) {
    float t = temp_vals[i];
    vals[i] = t / (1.F + (t >= 0 ? t : -t));
}

}
