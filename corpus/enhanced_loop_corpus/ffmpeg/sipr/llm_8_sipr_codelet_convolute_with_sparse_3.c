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
    int start, end;
    for (i = 0; i < pulses->n; i++) {
        start = pulses->x[i];
        end = (start + 5 < length) ? start + 5 : length; // Limit inner loop to at most 5 iterations
        for (j = start; j < end; j++) {
            out[j] += pulses->y[i] * shape[j - start]; // Reduced computational scope
        }
    }
}
