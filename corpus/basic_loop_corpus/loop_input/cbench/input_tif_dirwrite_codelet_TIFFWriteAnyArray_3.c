#include <inttypes.h>

typedef unsigned int uint32;
typedef unsigned char uint8;

uint32 n = 16777216; // 16M elements, ~128MB input (v: 16M*8=128MB), adjust for ~0.01 sec on modern CPU

double *v;
int i;
uint8 *bp;

void init_vars() {
    v = (double*)__builtin_malloc(n * sizeof(double));
    bp = (uint8*)__builtin_malloc(n * sizeof(uint8));
    for (uint32 idx = 0; idx < n; idx++) {
        v[idx] = (double)(idx % 1000) + 0.5;
    }
}