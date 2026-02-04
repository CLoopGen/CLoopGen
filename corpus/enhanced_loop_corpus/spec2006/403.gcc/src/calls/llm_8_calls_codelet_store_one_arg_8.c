#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int reg_parm_stack_space;
extern int i;
extern int lower_bound;
extern int upper_bound;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = lower_bound; i < upper_bound; i += step)
        if (stack_usage_map[i] && i > reg_parm_stack_space)
            break;
}
