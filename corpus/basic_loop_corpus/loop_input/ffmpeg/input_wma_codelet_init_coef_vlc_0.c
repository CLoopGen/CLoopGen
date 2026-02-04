#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *run_table;
uint16_t *level_table;
float *flevel_table;
int i;
int l;
int j;
int level;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements, adjust for ~0.01s runtime

    run_table = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    level_table = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    flevel_table = (float*)aligned_alloc(32, data_size * sizeof(float));

    if (!run_table || !level_table || !flevel_table) {
        exit(1);
    }

    i = 0;
    l = data_size;
    j = 0;
    level = 42;
}