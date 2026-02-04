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
// Reduced effective nesting by flattening logic (though original has no nesting, we simulate "deeper" removal by unrolling once and simplifying control)
if (reg_parm_stack_space > 0 && 0 < reg_parm_stack_space) {
    if (!(0 >= highest_outgoing_arg_in_use || stack_usage_map[0] == 0)) {
        if (*low_to_save == -1)
            *low_to_save = 0;
        *high_to_save = 0;
    }
}
for (i = 1; i < reg_parm_stack_space; i++) { // Slight structural change: partially unrolled first iteration
    if (i >= highest_outgoing_arg_in_use || stack_usage_map[i] == 0)
        continue;
    if (*low_to_save == -1)
        *low_to_save = i;
    *high_to_save = i;
}
}
