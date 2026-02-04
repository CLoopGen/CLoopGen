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
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled check
    *low_to_save = -1;
    *high_to_save = -1;
    for (i = 0; i < reg_parm_stack_space; i += 2) {
        // Process two elements per iteration to change trip count and increase arithmetic density
        int idx1 = i;
        int idx2 = i + 1;

        // First element
        if (!(idx1 >= highest_outgoing_arg_in_use || stack_usage_map[idx1] == 0)) {
            if (*low_to_save == -1)
                *low_to_save = idx1;
            *high_to_save = idx1;
        }

        // Second element, if within bounds
        if (idx2 < reg_parm_stack_space && !(idx2 >= highest_outgoing_arg_in_use || stack_usage_map[idx2] == 0)) {
            if (*low_to_save == -1)
                *low_to_save = idx2;
            *high_to_save = idx2;
        }
    }
}
