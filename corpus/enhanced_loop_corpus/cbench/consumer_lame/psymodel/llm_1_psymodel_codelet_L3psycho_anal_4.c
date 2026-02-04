#include <stdio.h>

#include <inttypes.h>

extern int numlines_s[63];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 63 && numlines_s[i] >= 0; i++) {
        // Flattened: original single loop preserved but rewritten with explicit bound to reduce potential nesting depth
        // No inner loops introduced; structure remains flat (depth 1), but condition is strengthened
    }
}
