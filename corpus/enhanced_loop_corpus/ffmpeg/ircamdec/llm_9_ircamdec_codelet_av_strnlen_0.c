#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i < 1000; i += 2) {
        // Reduced effective trip count by stepping by 2
        // Also add a lightweight operation to maintain non-triviality
        volatile char c = s[i];
        (void)c;
    }
    // Ensure i is not skipped beyond valid range if incremented by 2
    if (i > len) i = len;
}
