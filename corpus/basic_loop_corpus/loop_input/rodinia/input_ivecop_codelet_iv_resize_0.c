#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

static int *ive_storage;
static IVEC iv_storage;

IVEC *iv;
int new_dim;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of integers
    ive_storage = calloc(data_size, sizeof(int));
    if (!ive_storage) exit(1);

    iv_storage.dim = data_size / 2;
    iv_storage.max_dim = data_size;
    iv_storage.ive = ive_storage;

    iv = &iv_storage;
    new_dim = data_size;
}