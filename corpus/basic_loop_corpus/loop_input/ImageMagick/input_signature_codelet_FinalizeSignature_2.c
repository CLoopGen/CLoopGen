#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t i;
unsigned char *q;
unsigned int *p;

static unsigned int *p_data;
static unsigned char *q_data;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of uint32_t data to ensure ~0.01s runtime
    p_data = (unsigned int *)aligned_alloc(32, data_size * sizeof(unsigned int));
    q_data = (unsigned char *)aligned_alloc(32, data_size * sizeof(unsigned int) * 4); // 4 bytes per uint

    if (!p_data || !q_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        p_data[idx] = (unsigned int)(0x80000000 + idx); // arbitrary initialization
    }

    p = p_data;
    q = q_data;
}

__attribute__((destructor))
static void cleanup() {
    free(p_data);
    free(q_data);
}