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
        // Perform dummy access to maintain control flow dependence
        if (i + 1 < len && !s[i + 1]) {
            i++; // Adjust index early exit if next char is null
            break;
        }
    }
    // Correct final index if exited due to null terminator in stride
    if (i > 0 && i % 2 != 0 && i >= len) i--;
}
