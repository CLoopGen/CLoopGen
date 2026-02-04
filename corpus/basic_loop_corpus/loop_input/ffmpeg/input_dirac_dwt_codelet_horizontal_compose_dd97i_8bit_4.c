#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int x;
int w2 = 131072; // Size chosen so that arrays are ~512KB each, total ~1MB, suitable for ~0.01s runtime
int16_t *b;
int16_t *tmp;

void init_vars() {
    // Allocate memory for b and tmp
    // b needs to hold at least 2*w2 elements because of b[2*x+1] access
    // tmp needs to hold at least w2+2 elements due to tmp[x+1], tmp[x+2], and tmp[x-1] (so x>=1 required)
    b = (int16_t*)aligned_alloc(32, sizeof(int16_t) * (w2 * 2 + 32));
    tmp = (int16_t*)aligned_alloc(32, sizeof(int16_t) * (w2 + 3));

    if (!b || !tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize tmp with non-zero values to avoid trivial optimization
    srand((unsigned int)time(NULL));
    for (int i = 0; i < w2 + 3; i++) {
        tmp[i] = (int16_t)(rand() % 65536 - 32768);
    }

    // Initialize part of b that is read: b[x + w2] for x in [0, w2-1] => indices [w2, 2*w2-1]
    for (int i = w2; i < 2 * w2; i++) {
        b[i] = (int16_t)(rand() % 65536 - 32768);
    }

    // Zero-initialize the rest of b to ensure defined behavior
    for (int i = 0; i < w2; i++) {
        b[2*i] = 0;
        b[2*i+1] = 0;
    }
    for (int i = 2*w2; i < 2*w2 + 32; i++) {
        b[i] = 0;
    }
}