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
    int first_update = 1;
    for (i = reg_parm_stack_space - 1; i >= 0; i--) {
        if (i >= highest_outgoing_arg_in_use || stack_usage_map[i] == 0)
            continue;
        if (first_update) {
            *high_to_save = i;
            if (*low_to_save == -1)
                *low_to_save = i;
            first_update = 0;
        } else {
            *low_to_save = i;
        }
    }
}
