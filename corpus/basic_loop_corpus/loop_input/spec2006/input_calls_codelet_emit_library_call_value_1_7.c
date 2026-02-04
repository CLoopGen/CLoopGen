#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *stack_usage_map;
int highest_outgoing_arg_in_use;
int count;
int reg_parm_stack_space;
int low_to_save;
int high_to_save;

void init_vars() {
    reg_parm_stack_space = 64 * 1024 * 1024; // 64 million elements, ~64MB
    highest_outgoing_arg_in_use = reg_parm_stack_space;

    stack_usage_map = (char *)malloc(reg_parm_stack_space * sizeof(char));
    if (!stack_usage_map) {
        exit(1);
    }

    memset(stack_usage_map, 0, reg_parm_stack_space * sizeof(char));

    for (int i = reg_parm_stack_space / 4; i < reg_parm_stack_space / 2; i++) {
        stack_usage_map[i] = 1;
    }

    low_to_save = -1;
    high_to_save = -1;
}