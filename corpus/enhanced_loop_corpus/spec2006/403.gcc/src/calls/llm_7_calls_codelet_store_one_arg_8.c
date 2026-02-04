#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int reg_parm_stack_space;
extern int i;
extern int lower_bound;
extern int upper_bound;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_offset = 0;
    for (i = lower_bound; i < upper_bound; i++) {
        int idx = i + local_offset; // Introduce RAW: local_offset must be read before update
        if (stack_usage_map[idx] && idx > reg_parm_stack_space) {
            break;
        }
        local_offset += (i % 2); // Update depends on current i (WAR: write after read in next iteration)
    }
}
