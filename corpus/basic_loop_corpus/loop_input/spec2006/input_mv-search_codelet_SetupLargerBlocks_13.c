#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int max_pos;
int pos;
int *_o;
int *_i;
int *_j;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~256 MB of total integer data (64M integers, 4 bytes each)
    max_pos = data_size / sizeof(int);

    _i = (int*)malloc(max_pos * sizeof(int));
    _j = (int*)malloc(max_pos * sizeof(int));
    _o = (int*)malloc(max_pos * sizeof(int));

    for (int i = 0; i < max_pos; i++) {
        _i[i] = i & 0xFF;
        _j[i] = (i + 1) & 0xFF;
    }
}