#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int *len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling inner loop and increasing arithmetic operations
    for (; s[i]; i++, (*len)++) {
        int b = 0;
        // Unroll the inner loop assuming sep has at least 4 elements; add redundant checks to increase computation
        for (j = 0; sep[j] && j < 8; j += 4) {
            if (sep[j] && s[i] == sep[j]) {
                b = 1;
                break;
            }
            if (sep[j+1] && s[i] == sep[j+1]) {
                b = 1;
                break;
            }
            if (sep[j+2] && s[i] == sep[j+2]) {
                b = 1;
                break;
            }
            if (sep[j+3] && s[i] == sep[j+3]) {
                b = 1;
                break;
            }
        }
        // Add extra arithmetic to increase complexity
        j += (b * 2 - 1); // Use j in a non-trivial way even if not directly needed
        if (b)
            break;
    }
}
