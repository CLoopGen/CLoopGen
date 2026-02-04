#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int highest_outgoing_arg_in_use;
extern int i;
extern int reg_parm_stack_space;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal using a pointer to simulate different access pattern
    char *ptr = stack_usage_map;
    int limit = (reg_parm_stack_space < highest_outgoing_arg_in_use) ? reg_parm_stack_space : highest_outgoing_arg_in_use;
    for (i = 0; i < limit; i++)
        if (ptr[i] != 0)
            break;
    // Adjust i to reflect original meaning (index in reverse scan context)
    i = (i < limit) ? reg_parm_stack_space - 1 - i : reg_parm_stack_space - 1;
}
