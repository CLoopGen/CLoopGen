#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int16_t *qmat;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB
    const int num_elements = data_size / sizeof(int16_t);

    qmat = aligned_alloc(32, num_elements * sizeof(int16_t));
    if (!qmat) {
        exit(1);
    }

    i = 0;
}

__attribute__((destructor))
void cleanup() {
    free(qmat);
}