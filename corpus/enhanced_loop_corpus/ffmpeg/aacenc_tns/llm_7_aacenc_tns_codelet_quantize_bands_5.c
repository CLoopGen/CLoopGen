#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *out;
extern  float *in;
extern  float *scaled;
extern int size;
extern int is_signed;
extern int maxval;
extern  float Q34;
extern  float rounding;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float qc_prev = 0.0f;
    for (i = 0; i < size; i++) {
        float qc = scaled[i] * Q34 + qc_prev; // Introduce loop-carried dependency (WAW/RAR via qc_prev)
        qc_prev = qc * 0.1f; // Create loop-carried dependence: current iteration affects next
        int tmp = (int)((qc + rounding) > ((float)maxval) ? ((float)maxval) : (qc + rounding));
        if (is_signed && in[i] < 0.F) {
            tmp = -tmp;
        }
        out[i] = tmp;
    }
}
