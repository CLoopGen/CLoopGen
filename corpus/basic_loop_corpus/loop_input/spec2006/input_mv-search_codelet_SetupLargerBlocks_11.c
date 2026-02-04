#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int max_pos;
int pos;
int *_o;
int *_i;
int *_j;

void init_vars() {
    max_pos = 1 << 20; // Approximately 4 million integers, ~16 MB per array

    _i = (int*)malloc(max_pos * sizeof(int));
    _j = (int*)malloc(max_pos * sizeof(int));
    _o = (int*)malloc(max_pos * sizeof(int));

    for (int i = 0; i < max_pos; i++) {
        _i[i] = i;
        _j[i] = i * 2;
    }
}