#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int highest_outgoing_arg_in_use;
extern int i;
extern int reg_parm_stack_space;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = reg_parm_stack_space - 1; i >= 0; i--)
        for (int j = 0; j < 1; j++)
            if (i < highest_outgoing_arg_in_use && stack_usage_map[i] != 0)
                break;
}
