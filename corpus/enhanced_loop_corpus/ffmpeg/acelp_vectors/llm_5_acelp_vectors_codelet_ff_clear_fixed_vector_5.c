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
for (i = 0; i < in->n; i++) {
    int x = in->x[i];
    if (in->pitch_lag > 0) {
        out[x] = 0.;
        if (((in->no_repeat_mask >> i) & 1) == 0) {
            int next_x = x + in->pitch_lag;
            if (next_x < size) {
                out[next_x] = 0.;
            }
        }
    }
}
}
