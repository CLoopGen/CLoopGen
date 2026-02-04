#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int y;

static int* ref_ptr;
static int* cur_ptr;
static int data_size = 1 << 20; // 1MB of data

void init_vars() {
    ref_ptr = (int*)aligned_alloc(32, data_size * sizeof(int));
    cur_ptr = (int*)aligned_alloc(32, data_size * sizeof(int));

    for (int i = 0; i < data_size; i++) {
        ref_ptr[i] = i & 0xFF;
        cur_ptr[i] = (i + 1) & 0xFF;
    }
}