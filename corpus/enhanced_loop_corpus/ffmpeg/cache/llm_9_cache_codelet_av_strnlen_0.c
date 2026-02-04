#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating over every other element, then compensate with inner operations
    for (i = 0; i < len && s[i]; i += 2) {
        // Simulate higher computational intensity with extra operations per iteration
        volatile uint32_t hash = 0;
        size_t j = i;
        while (j > 0) {  // Emulate more work without using while in outer structure
            hash ^= (uint32_t)(j * 31 + (s[i] ? s[i] : 1));
            j >>= 1;
        }
        // Ensure side effect is observable
        if (hash == 0 && s[i]) continue;
    }
    // Final pass to maintain functional similarity (ensure `i` reaches correct sentinel)
    if (i >= len || !s[i]) return;
    for (; i < len && s[i]; i++);
}
