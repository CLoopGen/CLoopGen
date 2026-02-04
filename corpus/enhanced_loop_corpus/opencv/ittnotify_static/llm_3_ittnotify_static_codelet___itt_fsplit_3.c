#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (linear) access with reversed traversal for locality improvement
    // Traverse the separator list in reverse to test different cache behavior
    // Also process string s from start to end, but access sep consecutively backwards
    for (i = 0; s[i]; i++) {
        int b = 0;
        // Compute length of sep once per loop (simulates preparation for consecutive access)
        int len = 0;
        while (sep[len]) len++;
        // Traverse sep in reverse — still consecutive, but opposite order
        for (j = len - 1; j >= 0; j--) {
            if (s[i] == sep[j]) {
                b = 1;
                break;
            }
        }
        if (!b)
            break;
    }
}
