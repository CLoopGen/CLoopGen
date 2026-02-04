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
    // Variant 2: Strided memory access with step size of 2
    for (i = 0; i < reg_parm_stack_space; i += 2) {
        int idx = i;  // Strided access: every second element
        if (idx >= highest_outgoing_arg_in_use || stack_usage_map[idx] == 0)
            continue;
        if (*low_to_save == -1)
            *low_to_save = idx;
        *high_to_save = idx;
    }
    // Final pass for odd indices if needed to maintain correctness
    for (i = 1; i < reg_parm_stack_space; i += 2) {
        int idx = i;
        if (idx >= highest_outgoing_arg_in_use || stack_usage_map[idx] == 0)
            continue;
        if (*low_to_save == -1)
            *low_to_save = idx;
        *high_to_save = idx;
    }
}
