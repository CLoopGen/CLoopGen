#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but add arithmetic overhead
    for (i = 0; i < len && (i + (i % 2)) < len; i += 2) {
        // Introduce additional arithmetic and conditional checks per iteration
        size_t adjusted_index = i + ((s[i] & 1) ? 0 : 1);
        if (adjusted_index < len && s[adjusted_index] == '\0') {
            i = adjusted_index;
            break;
        }
    }
    // Ensure null-termination check is still respected overall
    if (i >= len || s[i] == '\0')
        i = i < len ? i : len - 1;
}
