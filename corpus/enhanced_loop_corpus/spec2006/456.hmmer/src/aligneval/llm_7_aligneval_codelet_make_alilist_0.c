#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int *s1_list;
extern int col;
extern int r1;
extern int r2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    int local_r1 = r1;
    int local_r2 = r2;
    int prev_col = -1;

    for (i = 0; s1[i] != '\x00'; i++) {
        // Introduce artificial loop-carried dependence via prev_col
        if (prev_col != -1) {
            // Create WAW dependency on s1_list by conditionally overwriting previous index
            if (((s1[prev_col]) == '-' && (s1[i]) == '_') && local_r1 > r1) {
                s1_list[local_r1 - 1] = local_r2; // Modify previously written element
            }
        }

        if (!((s1[i]) == ' ' || (s1[i]) == '.' || (s1[i]) == '_' || (s1[i]) == '-' || (s1[i]) == '~')) {
            s1_list[local_r1] = ((s2[i]) == ' ' || (s2[i]) == '.' || (s2[i]) == '_' || (s2[i]) == '-' || (s2[i]) == '~') ? -1 : local_r2;
            local_r1++;
        }
        if (!((s2[i]) == ' ' || (s2[i]) == '.' || (s2[i]) == '_' || (s2[i]) == '-' || (s2[i]) == '~')) {
            local_r2++;
        }

        prev_col = i; // Carry dependency to next iteration
    }

    r1 = local_r1;
    r2 = local_r2;
}
