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
extern int i;
extern int offset;
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_val = val;
    int local_x[3];
    float local_y[3];
    for (i = 0; i < 3; i++) {
        int index = (local_val & 7) * 6 + 4 - i * 2;
        local_y[i] = (offset + index) & 3 ? -1 : 1;
        local_x[i] = index;
        local_val >>= 3;
    }
    for (i = 0; i < 3; i++) {
        fixed_sparse->x[i] = local_x[i];
        fixed_sparse->y[i] = local_y[i];
    }
}
