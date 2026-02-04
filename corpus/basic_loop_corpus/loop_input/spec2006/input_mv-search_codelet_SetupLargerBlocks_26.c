#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int max_pos;
int pos;
int *_o;
int *_i;
int *_j;

void init_vars() {
    max_pos = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB total data (64M integers × 4 arrays)
    
    _i = (int*)aligned_alloc(32, max_pos * sizeof(int));
    _j = (int*)aligned_alloc(32, max_pos * sizeof(int));
    _o = (int*)aligned_alloc(32, max_pos * sizeof(int));

    for (int idx = 0; idx < max_pos; idx++) {
        _i[idx] = idx % 1000;
        _j[idx] = (idx + 1) % 1000;
        _o[idx] = 0;
    }
}