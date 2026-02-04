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
    for (j = 0; j < 64; j += 8) {
        int idx = j >> 3;
        int base = (i << 3) + (idx << 5);
        for (int k = 0; k < 8 && (j + k) < 64; k++) {
            sum += data[j + k] * ws[base + k];
        }
    }
    t = sum * wf[i] + wf[4 + i];
    vals[i] = t / (1.F + ((t) >= 0 ? (t) : (-(t))));
}
}
