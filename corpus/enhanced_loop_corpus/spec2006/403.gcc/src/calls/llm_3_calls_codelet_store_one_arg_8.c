#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int reg_parm_stack_space;
extern int i;
extern int lower_bound;
extern int upper_bound;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with local index shadowing for safety
    int idx;
    for (idx = lower_bound; idx < upper_bound; idx++) {
        i = idx;
        if (stack_usage_map[i] && i > reg_parm_stack_space)
            break;
    }
}
