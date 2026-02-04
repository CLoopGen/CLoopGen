#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int max_pos;
int pos;
int *_o;
int *_i;
int *_j;

void init_vars() {
    max_pos = 64 * 1024 * 1024 / sizeof(int);  // ~64M integers = ~256MB total for 3 arrays
    size_t bytes = max_pos * sizeof(int);

    _i = (int*)aligned_alloc(32, bytes);
    _j = (int*)aligned_alloc(32, bytes);
    _o = (int*)aligned_alloc(32, bytes);

    if (!_i || !_j || !_o) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < max_pos; i++) {
        _i[i] = i;
        _j[i] = i * 2;
        _o[i] = 0;
    }
}