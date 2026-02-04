#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int length;
int i;

#define DATA_SIZE (128 << 20)  // 128 MB of data

static int *data_array;

void init_vars() {
    data_array = (int *)aligned_alloc(32, DATA_SIZE);
    if (!data_array) {
        exit(1);
    }

    length = DATA_SIZE / sizeof(int);
}

__attribute__((constructor))
static void constructor_call() {
    init_vars();
}