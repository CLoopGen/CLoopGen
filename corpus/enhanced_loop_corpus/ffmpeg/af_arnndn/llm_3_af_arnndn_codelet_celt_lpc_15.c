#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lpc;
extern  float *ac;
extern int p;
extern float r;
extern float error;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < p; i++) {
    float rr = 0;
    float *lpc_base = lpc;
    float *ac_base = ac;
    for (int j = 0; j < i; j++) {
        rr += (*(lpc_base + j) * *(ac_base + i - j));
    }
    rr += *(ac_base + i + 1);
    r = -rr / error;
    *(lpc_base + i) = r;
    int bound = (i + 1) >> 1;
    for (int j = 0; j < bound; j++) {
        float tmp1 = *(lpc_base + j);
        float tmp2 = *(lpc_base + i - 1 - j);
        *(lpc_base + j) = tmp1 + (r * tmp2);
        *(lpc_base + i - 1 - j) = tmp2 + (r * tmp1);
    }
    error = error - (r * r * error);
    if (error < 0.00100000005F * (*ac_base))
        break;
}
}
