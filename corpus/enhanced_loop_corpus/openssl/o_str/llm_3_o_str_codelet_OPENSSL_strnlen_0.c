#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern size_t maxlen;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Use an auxiliary index array to traverse the string indirectly
    // Since we cannot define new global arrays, simulate indirect access using modulo-based indexing
    size_t i;
    for (i = 0; i < maxlen; ++i) {
        p = str + (i % maxlen);  // Simulate indirect access pattern
        if (*p == '\x00') {
            p = str + i;  // Adjust final `p` to reflect current position in original order
            break;
        }
        if (i == maxlen - 1)
            p = str + i;
    }
}
