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



void loop() {
    // Variant 1: Strided memory access on 'sep' array with fixed stride of 2
    // This changes the pattern from sequential to strided, assuming sep elements are accessed every 2nd index.
    for (; s[i]; i++, (*len)++) {
        int b = 0;
        for (j = 0; sep[j]; j += 2) {  // Strided access: step by 2
            if (j + 1 < 256 && sep[j + 1] == '\0') break;  // Safe bound check assuming max sep length
            if (s[i] == sep[j]) {
                b = 1;
                break;
            }
        }
        if (b) break;
    }
}
