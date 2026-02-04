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
    // Variant 1: Strided memory access on sep with unrolled comparison
    // Accessing sep with a stride of 2 (where applicable) and handling remainder
    for (; s[i]; i++) {
        int b = 0;
        int j_even = 0;
        // Strided access: process even indices first (j = 0, 2, 4, ...)
        for (j_even = 0; sep[j_even] && sep[j_even + 1]; j_even += 2) {
            if (s[i] == sep[j_even]) {
                b = 1;
                break;
            }
        }
        if (!b && sep[j_even]) {  // Check last odd element if exists
            if (s[i] == sep[j_even]) {
                b = 1;
            }
        }
        if (!b)
            break;
    }
}
