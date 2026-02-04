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
for (i = 0; i < 4; i++) {
    const int pos1 = (pulse_position[i] << 2) + i;
    const int pos2 = (pulse_position[i + 4] << 2) + i;
    const float sign = fixed_index[i] ? -1. : 1.;
    fixed_sparse->x[i] = pos1;
    fixed_sparse->x[i + 4] = pos2;
    fixed_sparse->y[i] = sign;
    fixed_sparse->y[i + 4] = pos2 < pos1 ? -sign : sign;
}

}
