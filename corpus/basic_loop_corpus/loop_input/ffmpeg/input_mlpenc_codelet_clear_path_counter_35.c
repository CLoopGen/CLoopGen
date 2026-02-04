#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    char path[19];
    int bitcount;
} PathCounter;

PathCounter *path_counter;
unsigned int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to ensure loop runtime around 0.01s
    const size_t num_elements = data_size / sizeof(PathCounter);
    path_counter = aligned_alloc(32, num_elements * sizeof(PathCounter));
    if (!path_counter) exit(1);

    for (size_t idx = 0; idx < num_elements; ++idx) {
        path_counter[idx].path[0] = 'X';
        path_counter[idx].path[1] = 0;
        for (int j = 2; j < 19; ++j) {
            path_counter[idx].path[j] = 0;
        }
        path_counter[idx].bitcount = -1;
    }

    i = 0;
}