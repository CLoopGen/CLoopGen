#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int highest_outgoing_arg_in_use;
extern int count;
extern int reg_parm_stack_space;
extern int low_to_save;
extern int high_to_save;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) forward traversal
    low_to_save = -1;
    high_to_save = -1;
    for (count = 0; count < reg_parm_stack_space; count += 2) {
        // Check current stride index
        if (count < reg_parm_stack_space && count < highest_outgoing_arg_in_use && stack_usage_map[count] != 0) {
            if (low_to_save == -1)
                low_to_save = count;
            high_to_save = count;
        }
        // Check next element in stride (to maintain logical coverage)
        int next_idx = count + 1;
        if (next_idx < reg_parm_stack_space && next_idx < highest_outgoing_arg_in_use && stack_usage_map[next_idx] != 0) {
            if (low_to_save == -1)
                low_to_save = next_idx;
            if (next_idx > high_to_save)
                high_to_save = next_idx;
        }
    }
    // Final pass on odd indices if needed to ensure correctness
    if (reg_parm_stack_space > 0 && low_to_save == -1) {
        for (count = 1; count < reg_parm_stack_space; count += 2) {
            if (count < highest_outgoing_arg_in_use && stack_usage_map[count] != 0) {
                low_to_save = count;
                high_to_save = count;
                break;
            }
        }
    }
}
