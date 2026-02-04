#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AMRFixed {
    int n;
    int x[10];
    float y[10];
    int no_repeat_mask;
    int pitch_lag;
    float pitch_fac;
} AMRFixed;

extern float *out;
extern  AMRFixed *pulses;
extern  float *shape;
extern int length;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < pulses->n && pulses->x[i] < length; i++) {
        int start = pulses->x[i];
        float gain = pulses->y[i];
        int idx;
        for (j = start, idx = 0; j < length; j++, idx++) {
            if (idx >= 10) break; // Artificial bound to introduce control divergence
            out[j] += gain * shape[idx];
        }
    }
}
