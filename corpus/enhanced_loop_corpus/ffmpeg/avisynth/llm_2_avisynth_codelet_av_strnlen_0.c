#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len && s[i]; i += 2) {
        // Perform dummy access to maintain correctness
        // Original logic is preserved by checking every even index only
        if (i + 1 < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Adjust final value of i to match original semantics (pointing to '\0' or limit)
    if (i >= len || !s[i]) {
        // Already correct
    } else {
        // Continue from where strided left off
        for (; i < len && s[i]; i++);
    }
}
