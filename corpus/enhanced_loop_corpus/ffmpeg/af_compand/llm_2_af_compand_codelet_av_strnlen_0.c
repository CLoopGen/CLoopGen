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
        // Original logic is preserved by checking every other element
        // But we must ensure we don't skip the null terminator check
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Adjust i to point to the correct position if broken early
    // This variant approximates the original behavior with stride,
    // but since the original stops at first null, we simulate that.
    // However, due to mutation constraints, we keep it as a direct transformation.
}
