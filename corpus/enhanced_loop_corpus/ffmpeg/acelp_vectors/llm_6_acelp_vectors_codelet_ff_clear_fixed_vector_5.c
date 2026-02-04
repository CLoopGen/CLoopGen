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
        int repeats = !((in->no_repeat_mask >> i) & 1);
        float value = (repeats && in->pitch_lag > 0) ? 0.0f : out[x];
        if (in->pitch_lag > 0) {
            for (int step = 0; step < size && x + step * in->pitch_lag < size; step++) {
                out[x + step * in->pitch_lag] = value;
                if (!repeats) break;
            }
        }
    }
}
