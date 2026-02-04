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
    const int limit = (half_pulse_count + 3) / 4 * 4; // Round up to multiple of 4 for unrolling
    for (i = 0; i < limit; i += 4) {
        for (int j = 0; j < 4 && (i + j) < half_pulse_count; j++) {
            const int pos1 = gray_decode[fixed_index[2*(i+j)+1] & mask] + (i+j);
            const int pos2 = gray_decode[fixed_index[2*(i+j)] & mask] + (i+j);
            const float sign = (fixed_index[2*(i+j)+1] & (1 << bits)) ? -1.0f : 1.0f;
            fixed_sparse->x[2*(i+j)+1] = pos1;
            fixed_sparse->x[2*(i+j)] = pos2;
            fixed_sparse->y[2*(i+j)+1] = sign;
            fixed_sparse->y[2*(i+j)] = pos2 < pos1 ? -sign : sign;
        }
    }
}
