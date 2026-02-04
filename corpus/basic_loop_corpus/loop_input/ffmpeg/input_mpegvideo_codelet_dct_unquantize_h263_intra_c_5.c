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
    nCoeffs = 65536; // Size to achieve ~0.01 sec runtime
    block = (int16_t*)aligned_alloc(32, (nCoeffs + 1) * sizeof(int16_t));
    if (!block) {
        exit(1);
    }

    for (i = 1; i <= nCoeffs; i++) {
        block[i] = (int16_t)(rand() % 2047 - 1023); // Random levels around zero
    }

    qmul = 3;
    qadd = 1;
    level = 0;
}