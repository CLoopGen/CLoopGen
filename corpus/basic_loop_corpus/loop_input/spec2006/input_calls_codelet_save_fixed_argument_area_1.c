#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *stack_usage_map;
int highest_outgoing_arg_in_use;
int reg_parm_stack_space;
int *low_to_save;
int *high_to_save;
int i;

static char internal_stack_usage_map[1 << 20]; // 1MB
static int internal_low_to_save;
static int internal_high_to_save;

void init_vars() {
    reg_parm_stack_space = 1 << 20; // 1 million elements
    highest_outgoing_arg_in_use = reg_parm_stack_space * 3 / 4;

    for (int j = 0; j < reg_parm_stack_space; j++) {
        internal_stack_usage_map[j] = (j % 7 != 0) ? 1 : 0;
    }

    stack_usage_map = internal_stack_usage_map;
    low_to_save = &internal_low_to_save;
    high_to_save = &internal_high_to_save;

    *low_to_save = -1;
    *high_to_save = -1;
}