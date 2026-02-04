#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char val;
    for (i = 0; i < len; i++) {
        val = s[i];  // Introduce explicit read into local variable
        if (!val)    // Use the loaded value in condition without re-reading s[i]
            break;   // Eliminates redundant load in original condition by splitting termination logic
        // Introduces a loop-carried dependency via control flow (break depends on prior loads)
        // RAW dependency: s[i] -> val, val -> if check
        // Reduces memory access redundancy, changes data usage pattern
    }
    // i now either points to the first null character within bounds or equals len
}
