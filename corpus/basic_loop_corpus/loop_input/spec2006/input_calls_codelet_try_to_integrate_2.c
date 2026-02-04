#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *stack_usage_map;
int highest_outgoing_arg_in_use;
int i;
int reg_parm_stack_space;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB

    stack_usage_map = (char *)malloc(data_size);
    if (!stack_usage_map) {
        exit(1);
    }

    reg_parm_stack_space = data_size;
    highest_outgoing_arg_in_use = data_size / 2;

    memset(stack_usage_map, 0, data_size);
    stack_usage_map[highest_outgoing_arg_in_use - 1] = 1;
}