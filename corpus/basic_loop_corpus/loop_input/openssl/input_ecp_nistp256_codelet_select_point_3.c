#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint64_t u64;

typedef u64 smallfelem[4];

u64 idx = 0;
unsigned int size = 128; // Adjusted to control data size
unsigned int i = 0;
unsigned int j = 0;
u64 *outlimbs = NULL;
smallfelem pre_comp[16][3];

void init_vars() {
    outlimbs = (u64*)calloc(4 * 3, sizeof(u64));
    if (!outlimbs) {
        exit(1);
    }
    for (unsigned int idx1 = 0; idx1 < 16; idx1++) {
        for (unsigned int idx2 = 0; idx2 < 3; idx2++) {
            for (int idx3 = 0; idx3 < 4; idx3++) {
                pre_comp[idx1][idx2][idx3] = (idx1 + idx2 + idx3) % 251;
            }
        }
    }
    idx = 5;
    size = 16;
}