#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int d1 = 65536;
int d2 = 4;
int elem_size = 16;
char *store;
char **out;
int i;
int j;

void init_vars() {
    store = (char *)aligned_alloc(32, (size_t)d1 * d2 * elem_size);
    out = (char **)aligned_alloc(32, (size_t)d1 * sizeof(char *));

    if (!store || !out) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < (d1 * d2 * elem_size); idx++) {
        store[idx] = (char)(idx & 0xFF);
    }

    for (int idx = 0; idx < d1; idx++) {
        out[idx] = NULL;
    }
}