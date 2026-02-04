#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float real_t;

__attribute__((aligned(64))) real_t aa[256][256];
__attribute__((aligned(64))) real_t bb[256][256];

void init_vars() {
    for (int j = 0; j < 256; j++) {
        for (int i = 0; i < 256; i++) {
            aa[j][i] = 1.0f + (i % 10) * 0.1f;
            bb[j][i] = 0.5f - (j % 5) * 0.1f;
        }
    }
}