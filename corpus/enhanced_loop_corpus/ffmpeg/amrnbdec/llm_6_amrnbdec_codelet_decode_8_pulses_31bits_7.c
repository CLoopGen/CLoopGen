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
extern int pulse_position[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sign_cache[8];
    int pos_cache[8];
    for (i = 0; i < 4; i++) {
        const int pos1 = (pulse_position[i] << 2) + i;
        const int pos2 = (pulse_position[i + 4] << 2) + i;
        const float sign = fixed_index[i] ? -1.f : 1.f;
        pos_cache[i] = pos1;
        pos_cache[i + 4] = pos2;
        sign_cache[i] = sign;
        sign_cache[i + 4] = (pos2 < pos1) ? -sign : sign;
    }
    for (i = 0; i < 8; i++) {
        fixed_sparse->x[i] = pos_cache[i];
        fixed_sparse->y[i] = sign_cache[i];
    }
}
