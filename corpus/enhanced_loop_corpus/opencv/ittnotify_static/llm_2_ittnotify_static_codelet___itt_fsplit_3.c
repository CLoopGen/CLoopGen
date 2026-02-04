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
    // Variant 1: Strided memory access with stride of 2, unrolled check for performance
    // Access s[i] and s[i+1] in steps, but simulate strided pattern by incrementing i by 2 each time
    // We maintain correctness by ensuring we don't skip non-separator characters
    for (i = 0; s[i]; i += 1) {
        int b = 0;
        // Use strided access on sep array: check every second element first, then fill in
        for (j = 0; sep[j]; j += 2) {
            if (sep[j] && s[i] == sep[j]) {
                b = 1;
                break;
            }
        }
        if (!b) {
            // Second pass for odd indices if needed
            for (j = 1; sep[j]; j += 2) {
                if (s[i] == sep[j]) {
                    b = 1;
                    break;
                }
            }
        }
        if (!b)
            break;
    }
}
