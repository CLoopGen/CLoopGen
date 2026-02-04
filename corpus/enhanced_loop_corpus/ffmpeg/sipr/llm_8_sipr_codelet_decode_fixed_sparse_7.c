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
for (i = 0; i < 6; i++) {
    int index = (val & 7) * 6 + 4 - i;
    fixed_sparse->y[i % 3] = ((offset + index) & 3) ? -1.0f : 1.0f;
    fixed_sparse->x[i % 3] = index;
    if (i % 2 == 0) val >>= 2;
}
}
