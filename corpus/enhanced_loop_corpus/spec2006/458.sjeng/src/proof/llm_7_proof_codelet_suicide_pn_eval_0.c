#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern int j;
extern int a;
extern int i;
extern int wp;
extern int bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_a = 1;
    int local_j = 1;
    // Eliminate loop-carried dependency on 'a' by decoupling increment logic
    for (; local_j < 62 && local_a <= piece_count; local_j++) {
        i = pieces[local_j];
        if (!i) {
            // No update to local_a, creating RAW dependency on i
            continue;
        } else {
            local_a++; // Update of local_a depends on prior value (WAW introduced locally)
        }
        // Reorder memory access to create WAR-like pattern (write before read in next iter not applicable due to break)
        int b_val = board[i];
        if (b_val >= 1 && b_val <= 12) {
            if ((b_val & 1) || b_val == 11) {
                wp++;
            } else {
                bp++;
            }
        }
        if (wp && bp)
            break;
    }
    // Carry final values out — maintains original side effects
    a = local_a;
    j = local_j;
}
