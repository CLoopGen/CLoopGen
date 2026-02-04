#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

IVEC *iv;
int i;
int i_min;
int min_val;
int tmp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 million integers, ~256MB
    int *data = (int*)malloc(data_size * sizeof(int));
    if (!data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        data[idx] = rand();
    }

    iv = (IVEC*)malloc(sizeof(IVEC));
    if (!iv) {
        free(data);
        exit(1);
    }

    iv->dim = data_size;
    iv->max_dim = data_size;
    iv->ive = data;

    i = 0;
    i_min = 0;
    min_val = data[0];
    tmp = 0;
}