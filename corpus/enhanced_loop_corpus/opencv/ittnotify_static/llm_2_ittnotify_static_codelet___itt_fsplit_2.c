#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of checking every character sequentially, we check with a stride of 2
    // and handle the remainder with an offset pass. This changes spatial locality.
    int stride = 2;
    int found_non_sep = 0;

    // Strided forward pass
    for (; s[i] && !found_non_sep; i += stride) {
        int b = 0;
        for (j = 0; sep[j]; j++) {
            if (s[i] == sep[j]) {
                b = 1;
                break;
            }
        }
        if (!b) {
            // Backtrack to ensure we didn't skip the first non-separator
            for (int k = i - stride + 1; k < i && s[k]; k++) {
                int inner_b = 0;
                for (j = 0; sep[j]; j++) {
                    if (s[k] == sep[j]) {
                        inner_b = 1;
                        break;
                    }
                }
                if (!inner_b) {
                    i = k;
                    found_non_sep = 1;
                    break;
                }
            }
            if (!found_non_sep) {
                i = i - stride + 1; // Adjust position to actual non-sep char
                found_non_sep = 1;
            }
        }
    }

    // Final sequential scan in case we overshot due to stride
    if (!found_non_sep) {
        for (; s[i]; i++) {
            int b = 0;
            for (j = 0; sep[j]; j++)
                if (s[i] == sep[j]) {
                    b = 1;
                    break;
                }
            if (!b)
                break;
        }
    }
}
