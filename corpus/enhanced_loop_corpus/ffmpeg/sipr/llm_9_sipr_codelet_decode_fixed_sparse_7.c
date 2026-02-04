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
for (i = 0; i < 2; i++) {
    int base_index = (val & 3) * 5 + 2;
    fixed_sparse->y[i] = (offset + base_index) & 1 ? -1.5f : 1.5f;
    fixed_sparse->x[i] = base_index;
    fixed_sparse->y[i + 2] = (offset + base_index + 1) & 1 ? -0.5f : 0.5f;
    fixed_sparse->x[i + 2] = base_index + 1;
    val >>= 4;
}
}
