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
    if (pulses->n <= 0) return;
    for (i = 0; i < pulses->n; i++) {
        int offset = pulses->x[i];
        float yi = pulses->y[i];
        if (offset >= length) continue;
        for (j = offset; j < length; j++) {
            out[j] += yi * shape[j - offset];
        }
    }
}
