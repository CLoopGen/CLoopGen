#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int highest_outgoing_arg_in_use;
extern int i;
extern int reg_parm_stack_space;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i = reg_parm_stack_space - 1;
    for (i = temp_i; i >= 0; i--) {
        if (i < highest_outgoing_arg_in_use && stack_usage_map[i] != 0) {
            temp_i = i;  // Introduce WAW dependence: temp_i written after original assignment
            break;
        }
    }
    i = temp_i;  // Additional write to i after loop (WAW dependency with loop index)
}
