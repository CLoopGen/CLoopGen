#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int max_pos;
int pos;
int *_o;
int *_i;
int *_j;

void init_vars() {
    max_pos = 1 << 20; // 1 million elements, ~4MB per array, total ~12MB

    _i = (int*)malloc(max_pos * sizeof(int));
    _j = (int*)malloc(max_pos * sizeof(int));
    _o = (int*)malloc(max_pos * sizeof(int));

    for (int i = 0; i < max_pos; i++) {
        _i[i] = i;
        _j[i] = i * 2;
        _o[i] = 0;
    }
}