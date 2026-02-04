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
int idx, i, j;
for (idx = 0; idx < pulses->n; idx++) {
    i = pulses->x[idx];
    float yval = pulses->y[idx];
    for (j = i; j < length; j++) {
        out[j] += yval * shape[j - i];
    }
}
}
