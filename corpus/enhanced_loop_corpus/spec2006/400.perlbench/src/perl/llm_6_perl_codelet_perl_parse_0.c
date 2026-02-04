#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern int PL_origargc;
extern char **PL_origargv;
extern char *s;
extern int i;
extern UV mask;
extern UV aligned;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UV local_mask = mask;
    char **argv_copy = PL_origargv;
    char *local_s = s;
    int local_i = 1;
    int reached_end = 0;

    for (; local_i < PL_origargc && !reached_end; local_i++) {
        char *current_arg = argv_copy[local_i];
        UV arg_val = (UV)current_arg;
        UV s_plus_1 = (UV)(local_s + 1);
        UV s_plus_8_aligned = (arg_val & local_mask);

        // Eliminate loop-carried dependency on 's' by deferring write until loop end
        // Introduce artificial WAW dependency via temporary
        if ((current_arg == local_s + 1) || 
            (aligned && (current_arg > local_s && current_arg <= (char*)s_plus_8_aligned))) {
            // Predict end of string without using while
            int j;
            for (j = 0; j < 256; j++) { // Bounded scan to avoid while
                if (current_arg[j] == '\0') break;
            }
            local_s = current_arg + j; // Update only after scanning
        } else {
            reached_end = 1;
        }
    }
    // Final write to shared 's' — creates WAW dependency outside loop
    s = local_s;
}
