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

AMRFixed *fixed_sparse;
int i;
int offset;
int val;

void init_vars() {
    fixed_sparse = (AMRFixed*)aligned_alloc(32, sizeof(AMRFixed));
    if (!fixed_sparse) {
        exit(1);
    }
    fixed_sparse->n = 0;
    for (int j = 0; j < 10; j++) {
        fixed_sparse->x[j] = 0;
        fixed_sparse->y[j] = 0.0f;
    }
    fixed_sparse->no_repeat_mask = 0;
    fixed_sparse->pitch_lag = 0;
    fixed_sparse->pitch_fac = 0.0f;

    i = 0;
    offset = 0x123456;
    val = 0xABCDEF;
}