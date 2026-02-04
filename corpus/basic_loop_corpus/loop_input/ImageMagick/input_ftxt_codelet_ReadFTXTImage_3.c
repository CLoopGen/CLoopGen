#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float MagickFloatType;
typedef MagickFloatType Quantum;

int i;
int nExpCh = 64;
long double chVals[64];
Quantum *q;

void init_vars() {
    q = (Quantum *)aligned_alloc(_Alignof(Quantum), nExpCh * sizeof(Quantum));
    for (int idx = 0; idx < nExpCh; idx++) {
        chVals[idx] = (long double)(idx * 3.14159L);
        q[idx] = 0.0f;
    }
}