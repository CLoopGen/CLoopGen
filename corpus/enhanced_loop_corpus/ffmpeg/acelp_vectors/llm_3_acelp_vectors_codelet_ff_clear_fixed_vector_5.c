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
    float *out_local = out;
    AMRFixed *in_local = in;
    int n = in_local->n;
    int pitch_lag = in_local->pitch_lag;
    const int *x_arr = in_local->x;
    int no_repeat_mask = in_local->no_repeat_mask;
    for (i = 0; i < n; i++) {
        int x = x_arr[i];
        int repeats = !((no_repeat_mask >> i) & 1);
        if (pitch_lag > 0) {
            int j;
            for (j = 0; j < size; j += pitch_lag) {
                int idx = x + j;
                if (idx >= size) break;
                out_local[idx] = 0.;
                if (!repeats) break;
            }
        }
    }
}
