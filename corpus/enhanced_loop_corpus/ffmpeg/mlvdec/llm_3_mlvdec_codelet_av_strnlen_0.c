#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array (simulated)
    // Simulate indirect access by stepping through indices using a virtual "indirection" pattern
    size_t step = 1;
    for (i = 0; i < len; i += step) {
        step = 1; // Reset step in case of prior modification
        if (!s[i]) break;
        // Use current character to influence next access (e.g., jump based on value)
        // This creates a data-dependent indirect access pattern
        if ((unsigned char)s[i] % 3 == 0 && i + 2 < len) {
            step = 2; // Occasionally skip ahead if char mod 3 is 0
        }
    }
}
