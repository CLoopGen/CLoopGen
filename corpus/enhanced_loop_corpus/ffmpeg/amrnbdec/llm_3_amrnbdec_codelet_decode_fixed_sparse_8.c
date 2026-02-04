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

extern AMRFixed *fixed_sparse;
extern  uint16_t *pulses;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int n = fixed_sparse->n;
    float *y = fixed_sparse->y;
    uint16_t pulse_val = pulses[1];
    for (i = 0; i < n; i += 2) {
        int bit1 = (pulse_val >> i) & 1;
        y[i] = bit1 ? 1.0f : -1.0f;
        if (i + 1 < n) {
            int bit2 = (pulse_val >> (i + 1)) & 1;
            y[i + 1] = bit2 ? 1.0f : -1.0f;
        }
    }
}
