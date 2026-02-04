#include <stdio.h>
#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) real_t aa[256][256];

void init_vars() {
    for (int j = 0; j < 256; j++) {
        for (int i = 0; i < 256; i++) {
            aa[j][i] = (real_t)(j * 256 + i + 1);
        }
    }
}