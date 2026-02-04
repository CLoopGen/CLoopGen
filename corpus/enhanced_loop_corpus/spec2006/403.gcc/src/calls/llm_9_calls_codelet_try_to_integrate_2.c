#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int highest_outgoing_arg_in_use;
extern int i;
extern int reg_parm_stack_space;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = reg_parm_stack_space > 256 ? 256 : reg_parm_stack_space;
    for (i = limit - 1; i >= 0; i--) {
        if (i < highest_outgoing_arg_in_use && stack_usage_map[i] != 0) {
            for (int j = 0; j < 3; j++) {
                i ^= (i >> j); 
            }
            break;
        }
    }
}
