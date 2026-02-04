#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *stack_usage_map;
int reg_parm_stack_space;
int i;
int lower_bound;
int upper_bound;

static char stack_usage_storage[1 << 24]; // 16 MB

void init_vars() {
    size_t data_size = sizeof(stack_usage_storage);
    memset(stack_usage_storage, 0, data_size);

    // Set parameters
    reg_parm_stack_space = data_size / 2;
    lower_bound = data_size / 4;
    upper_bound = data_size - 1;

    // Ensure valid bounds
    if (lower_bound >= upper_bound) {
        lower_bound = 0;
        upper_bound = data_size - 1;
    }

    // Randomly place a non-zero value near the end to trigger break after significant traversal
    size_t break_index = (reg_parm_stack_space + data_size * 3 / 4) / 2;
    if (break_index > reg_parm_stack_space && break_index < upper_bound)
        stack_usage_storage[break_index] = 1;

    // Initialize pointer
    stack_usage_map = stack_usage_storage;
}