#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided forward traversal with step 1 but accessed in reverse order per block of 2
    // Alters access pattern by reading s[i+1] before s[i] in pairs
    for (i = 0; i < len - 1; i += 2) {
        if (!s[i + 1]) { i++; break; }
        if (!s[i]) { i--; break; }
    }
    // Final pass to align with original behavior: find first null or end
    for (; i < len && s[i]; i++);
}
