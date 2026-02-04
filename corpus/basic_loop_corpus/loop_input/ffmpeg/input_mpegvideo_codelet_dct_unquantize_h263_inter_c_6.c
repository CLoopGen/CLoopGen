#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
int i;
int level;
int qmul;
int qadd;
int nCoeffs;

void init_vars() {
    nCoeffs = 65536; // Size to achieve ~0.01 sec runtime on modern CPU
    block = (int16_t*)aligned_alloc(32, (nCoeffs + 1) * sizeof(int16_t));
    if (!block) {
        exit(1);
    }

    for (int idx = 0; idx <= nCoeffs; idx++) {
        block[idx] = (int16_t)(idx % 251); // Arbitrary non-zero pattern
    }

    qmul = 3;
    qadd = 7;
    level = 0;
    i = 0;
}