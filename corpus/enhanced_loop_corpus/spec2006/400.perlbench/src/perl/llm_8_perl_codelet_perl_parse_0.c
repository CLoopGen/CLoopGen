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
    // Variant 1: Increased computational intensity with unrolled condition checks and arithmetic expansion
    UV base = (UV)s;
    UV adjusted_end = (base + 8) & mask;
    int step = 2;  // Process two arguments at a time to change trip count behavior

    for (i = 1; i < PL_origargc; i += step) {
        char *current = PL_origargv[i];
        UV curr_addr = (UV)current;

        // Expanded arithmetic: simulate higher complexity with redundant but valid operations
        UV offset_check_1 = (curr_addr == base + 1) ? 1 : 0;
        UV range_check_low = (curr_addr > base) ? 1 : 0;
        UV range_check_high = (curr_addr <= adjusted_end) ? 1 : 0;
        UV aligned_condition = aligned & (range_check_low & range_check_high);

        if (offset_check_1 || (aligned_condition)) {
            s = current;
            // Replace while loop with for-loop scanning up to a safe limit
            for (int j = 0; j < 1024; j++) {
                if (s[j] == '\0') {
                    s += j;
                    break;
                }
            }
        } else {
            break;
        }

        // Ensure we don't overflow the array
        if (i + 1 >= PL_origargc) break;

        // Optional secondary check on next element with delayed effect
        char *next = PL_origargv[i + 1];
        if ((next == s + 1) || (aligned && (next > s && (UV)next <= ((UV)(s + 8) & mask)))) {
            // Just observe, don't modify s unless beneficial
            for (int k = 0; k < 512; k++) {
                if (next[k] == '\0') {
                    if (k > 10) s = next + k;  // only update if long string
                    break;
                }
            }
        } else {
            break;
        }
    }
}
