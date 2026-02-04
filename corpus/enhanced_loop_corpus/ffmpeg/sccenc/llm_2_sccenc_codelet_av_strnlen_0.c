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
        // Access every second element; ensure bounds
        if ((i + 1) < len && s[i + 1] == '\0') {
            i++; // Adjust index if next char is null terminator
            break;
        }
    }
    // Correct final position if exited early due to stride
    for (; i < len && s[i] != '\0'; i++);
}
