#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int y;

static int *ref_ptr;
static int *cur_ptr;
static int data_size;
static int outer_bound;
static int inner_bound;

void init_vars() {
    data_size = 1 << 20; // 1MB of data (about 262,144 integers)
    ref_ptr = malloc(data_size);
    cur_ptr = malloc(data_size);

    outer_bound = 8;
    inner_bound = 8;

    for (int i = 0; i < data_size / sizeof(int); i++) {
        ref_ptr[i] = i & 0xFF;
        cur_ptr[i] = (i + 1) & 0xFF;
    }
}

__attribute__((constructor))
static void constructor_call() {
    init_vars();
}