#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *refl;
int *b1;
int *b2;
int i;
int j;

static int *refl_data;
static int *b1_data;
static int *b2_data;
static size_t data_size = 1 << 20; // ~4MB total data (1M elements per array)

void init_vars() {
    refl_data = calloc(data_size, sizeof(int));
    b1_data = calloc(data_size, sizeof(int));
    b2_data = calloc(data_size, sizeof(int));

    if (!refl_data || !b1_data || !b2_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        refl_data[idx] = rand() % 100;
        b1_data[idx] = rand() % 100;
        b2_data[idx] = rand() % 100;
    }

    refl = refl_data;
    b1 = b1_data;
    b2 = b2_data;
    i = 0;
    j = 0;
}