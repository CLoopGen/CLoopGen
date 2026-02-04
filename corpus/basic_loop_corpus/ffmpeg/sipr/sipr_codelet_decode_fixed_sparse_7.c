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
for (i = 0; i < 3; i++) {
    int index = (val & 7) * 6 + 4 - i * 2;
    fixed_sparse->y[i] = (offset + index) & 3 ? -1 : 1;
    fixed_sparse->x[i] = index;
    val >>= 3;
}

}
