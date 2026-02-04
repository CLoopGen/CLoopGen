#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned long HARD_REG_ELT_TYPE;

HARD_REG_ELT_TYPE *regs_live_at;
int born_index;
int dead_index;
int ins;
HARD_REG_ELT_TYPE used;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec on modern CPU)
    regs_live_at = (HARD_REG_ELT_TYPE*)aligned_alloc(sizeof(HARD_REG_ELT_TYPE), data_size);
    if (!regs_live_at) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    size_t num_elements = data_size / sizeof(HARD_REG_ELT_TYPE);
    for (size_t i = 0; i < num_elements; i++) {
        regs_live_at[i] = (HARD_REG_ELT_TYPE)(i * 314159UL + 1); // Non-zero pattern to simulate realistic data
    }

    born_index = 0;
    dead_index = (int)(num_elements < (size_t)INT32_MAX ? num_elements : INT32_MAX);
    used = 0;
}