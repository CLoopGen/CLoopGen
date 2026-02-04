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
    for (i = 0; i < 2; i++) {
        const int pos1_0 = (pulse_position[i] << 2) + i;
        const int pos2_0 = (pulse_position[i + 4] << 2) + i;
        const float sign_0 = fixed_index[i] ? -1.f : 1.f;
        fixed_sparse->x[i] = pos1_0;
        fixed_sparse->x[i + 4] = pos2_0;
        fixed_sparse->y[i] = sign_0;
        fixed_sparse->y[i + 4] = pos2_0 < pos1_0 ? -sign_0 : sign_0;

        const int next_i = i + 2;
        const int pos1_1 = (pulse_position[next_i] << 2) + next_i;
        const int pos2_1 = (pulse_position[next_i + 4] << 2) + next_i;
        const float sign_1 = fixed_index[next_i] ? -1.f : 1.f;
        fixed_sparse->x[next_i] = pos1_1;
        fixed_sparse->x[next_i + 4] = pos2_1;
        fixed_sparse->y[next_i] = sign_1;
        fixed_sparse->y[next_i + 4] = pos2_1 < pos1_1 ? -sign_1 : sign_1;
    }
}
