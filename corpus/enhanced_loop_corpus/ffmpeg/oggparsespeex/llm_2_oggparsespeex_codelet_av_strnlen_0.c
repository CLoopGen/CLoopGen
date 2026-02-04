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
        // Access every second element; ensure we don't exceed bounds
        if (i + 1 < len && s[i + 1] == '\0') {
            i++; // If next char is null, adjust to reflect correct position
            break;
        }
    }
    // Correct final position if exited due to stride and null was skipped
    if (i >= len || !s[i]) i = (i >= len) ? len : i;
}
