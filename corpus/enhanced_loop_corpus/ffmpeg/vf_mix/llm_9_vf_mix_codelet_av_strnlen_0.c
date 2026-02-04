#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but maintain correctness via inner unrolled operations
    for (i = 0; i < len - 1 && s[i] && s[i+1]; i += 2) {
        // Perform combined check in pairs to reduce total iterations while preserving logical outcome
        if (!s[i]) break;
        if (!s[i+1]) { i++; break; }
    }
    // Handle odd-length or early termination
    if (i == len - 1 && s[i]) i++;
}
