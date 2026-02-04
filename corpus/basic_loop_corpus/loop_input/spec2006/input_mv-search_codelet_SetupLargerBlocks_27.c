#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int max_pos;
int pos;
int *_o;
int *_i;
int *_j;

void init_vars() {
    max_pos = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB total data (64M ints × 4 bytes × 4 arrays approx)
    
    _i = (int*)aligned_alloc(32, max_pos * sizeof(int));
    _j = (int*)aligned_alloc(32, max_pos * sizeof(int));
    _o = (int*)aligned_alloc(32, max_pos * sizeof(int));

    for (int i = 0; i < max_pos; i++) {
        _i[i] = i & 0xFF;
        _j[i] = (i >> 8) & 0xFF;
        _o[i] = 0;
    }
}