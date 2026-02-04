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
    float *temp_out = out;
    int n = pulses->n;
    int *x = pulses->x;
    float *y = pulses->y;
    for (i = 0; i < n; i++) {
        float yi = y[i];
        int xi = x[i];
        for (j = xi; j < length; j++) {
            temp_out[j] += yi * shape[j - xi];
        }
    }
}
