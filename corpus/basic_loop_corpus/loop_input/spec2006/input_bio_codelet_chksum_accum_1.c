#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int int32;
typedef unsigned int uint32;
typedef unsigned short uint16;

int32 n_el;
uint32 sum;
int32 i;
uint16 *i16;

void init_vars() {
    n_el = 1 << 17; // 128K elements, ~256KB of data, suitable for ~0.01 sec runtime
    sum = 0;
    i = 0;
    i16 = (uint16*)malloc(n_el * sizeof(uint16));
    for (int32 j = 0; j < n_el; j++) {
        i16[j] = (uint16)(j & 0xFFFF);
    }
}