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

extern  int16_t *fixed_index;
extern AMRFixed *fixed_sparse;
extern  uint8_t *gray_decode;
extern int half_pulse_count;
extern int bits;
extern int i;
extern int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < half_pulse_count; i++) {
    const int raw_idx1 = fixed_index[2 * i + 1];
    const int raw_idx0 = fixed_index[2 * i];
    const int dec1 = gray_decode[raw_idx1 & mask];
    const int dec0 = gray_decode[raw_idx0 & mask];
    const int pos1 = dec1 + i;
    const int pos2 = dec0 + i;

    if (pos1 < 0 || pos2 >= 10) continue;

    const float base_sign = (raw_idx1 & (1 << bits)) ? -1.0f : 1.0f;
    const float sign1 = base_sign;
    const float sign0 = (pos2 < pos1) ? -base_sign : base_sign;

    fixed_sparse->x[2 * i + 1] = pos1;
    fixed_sparse->x[2 * i] = pos2;
    fixed_sparse->y[2 * i + 1] = sign1;
    fixed_sparse->y[2 * i] = sign0;
}
}
