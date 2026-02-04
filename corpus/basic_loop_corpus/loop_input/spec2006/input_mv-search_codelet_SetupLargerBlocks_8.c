#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int max_pos;
int pos;
int *_o;
int *_i;
int *_j;

void init_vars() {
    max_pos = 67108864; // 64 million elements, ~256MB total for three int arrays (assuming 4 bytes per int)

    _o = (int*)malloc(max_pos * sizeof(int));
    _i = (int*)malloc(max_pos * sizeof(int));
    _j = (int*)malloc(max_pos * sizeof(int));

    if (!_o || !_i || !_j) {
        exit(1);
    }

    for (int i = 0; i < max_pos; i++) {
        _i[i] = i % 1000;
        _j[i] = (i + 500) % 1000;
    }
}