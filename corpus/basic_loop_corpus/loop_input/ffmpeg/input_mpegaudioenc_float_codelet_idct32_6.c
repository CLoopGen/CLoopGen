#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *tab;
int j;

static int *tab_storage;

void init_vars() {
    size_t data_size = 1 << 20;
    tab_storage = aligned_alloc(64, data_size * sizeof(int));
    if (!tab_storage) {
        exit(1);
    }
    tab = tab_storage;

    for (size_t i = 0; i < data_size; ++i) {
        tab[i] = rand();
    }

    j = 0;
}