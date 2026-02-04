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
    // Variant 2: Reduced trip count with higher per-iteration cost using bit manipulation and indirect access
    low_to_save = -1;
    high_to_save = -1;
    int step = (reg_parm_stack_space > 8) ? reg_parm_stack_space / 8 : 1; // Limit iterations to at most 8
    for (count = 0; count < reg_parm_stack_space; count += step) {
        // Use a sliding window check over a range to increase computation per iteration
        int local_min = -1, local_max = -1;
        int start = count;
        int end = (count + step < reg_parm_stack_space) ? count + step : reg_parm_stack_space;
        for (int j = start; j < end; j++) {
            if (j >= highest_outgoing_arg_in_use || stack_usage_map[j] == 0)
                continue;
            if (local_min == -1)
                local_min = j;
            local_max = j;
        }
        // Aggregate results across chunks
        if (local_min != -1) {
            if (low_to_save == -1)
                low_to_save = local_min;
            high_to_save = local_max;
        }
        // Add computational overhead via bit counting
        volatile int bits = 0;
        for (int k = start; k < end; k++)
            bits += __builtin_popcount((unsigned int)(stack_usage_map[k]));
        (void)bits;
    }
}
