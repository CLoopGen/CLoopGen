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
extern  AMRFixed *in;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < in->n && in->pitch_lag > 0; i++) {
        int x = in->x[i];
        int repeats = !((in->no_repeat_mask >> i) & 1);
        int iterations = repeats ? (size - x + in->pitch_lag - 1) / in->pitch_lag : 1;
        for (int iter = 0; iter < iterations && x < size; iter++) {
            out[x] = 0.0f;
            x += in->pitch_lag;
        }
    }
}
