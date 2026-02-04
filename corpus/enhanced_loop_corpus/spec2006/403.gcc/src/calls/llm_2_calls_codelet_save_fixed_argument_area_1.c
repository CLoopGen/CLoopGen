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
    // Variant 1: Consecutive memory access with reversed iteration order
    for (i = reg_parm_stack_space - 1; i >= 0; i--) {
        int idx = i;  // Access is consecutive but in reverse
        if (idx >= highest_outgoing_arg_in_use || stack_usage_map[idx] == 0)
            continue;
        if (*low_to_save == -1)
            *low_to_save = idx;
        *high_to_save = idx;
    }
}
