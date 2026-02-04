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
        // Access every second element; ensure bounds and null check still apply
        if (i + 1 < len && s[i + 1] == '\0') {
            i++; // Adjust index to point to the actual null terminator
            break;
        }
    }
    // Correct final position if exited due to stride skipping the null byte
    if (i >= len || !s[i]) i = (i >= len) ? len : i;
}
