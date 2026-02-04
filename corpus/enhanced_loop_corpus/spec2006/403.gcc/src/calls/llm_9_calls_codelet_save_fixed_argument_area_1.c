#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int highest_outgoing_arg_in_use;
extern int reg_parm_stack_space;
extern int *low_to_save;
extern int *high_to_save;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased per-iteration computation using indirect addressing and arithmetic weight
    *low_to_save = -1;
    *high_to_save = -1;
    int step = (reg_parm_stack_space > 16) ? reg_parm_stack_space / 8 : 1; // Larger steps reduce iterations
    for (i = 0; i < reg_parm_stack_space; i += step) {
        // Use modulo to simulate dense scanning effect despite large step
        int effective_i = (i * 7 + 3) % reg_parm_stack_space; // Nonlinear access pattern

        if (effective_i >= highest_outgoing_arg_in_use || stack_usage_map[effective_i] == 0)
            continue;

        // Accumulate min/max using arithmetic comparisons instead of direct assignment
        *low_to_save = (*low_to_save == -1) ? effective_i : (*low_to_save < effective_i ? *low_to_save : effective_i);
        *high_to_save = (*high_to_save > effective_i) ? *high_to_save : effective_i;
    }
}
