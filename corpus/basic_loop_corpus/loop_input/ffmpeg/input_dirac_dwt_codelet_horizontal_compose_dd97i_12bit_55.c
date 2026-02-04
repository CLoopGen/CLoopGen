#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int w2 = 131072; // Size chosen so that the loop runs ~131k iterations, data size ~512KB (w2 * 4 * 2 arrays)
int32_t *b;
int32_t *tmp;

void init_vars() {
    // Allocate b and tmp arrays with size w2 + w2 to safely access index x + w2 - 1 when x = w2 - 1
    b = (int32_t*)calloc(w2 + w2, sizeof(int32_t));
    tmp = (int32_t*)calloc(w2 + w2, sizeof(int32_t));

    if (!b || !tmp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize b with non-zero values for meaningful computation
    for (int i = 0; i < w2 + w2; i++) {
        b[i] = rand() % 1000;
    }
}