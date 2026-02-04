#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int goal_alternative_matches[30];
extern int goal_alternative_matched[30];
extern char goal_alternative_win[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Processes even indices first, then odd if within bounds
    int i_even, i_odd;
    for (i_even = 0; i_even < noperands; i_even += 2) {
        if (!goal_alternative_win[i_even] && goal_alternative_matches[i_even] >= 0)
            goal_alternative_matched[goal_alternative_matches[i_even]] = i_even;
        
        i_odd = i_even + 1;
        if (i_odd < noperands) {
            if (!goal_alternative_win[i_odd] && goal_alternative_matches[i_odd] >= 0)
                goal_alternative_matched[goal_alternative_matches[i_odd]] = i_odd;
        }
    }
}
