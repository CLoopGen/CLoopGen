#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but perform more work per iteration
    for (i = 0; i < len && s[i]; i += 2) {
        // Simulate higher computational intensity with multiple redundant checks and operations
        if (i + 1 < len) {
            volatile char combined = s[i] ^ s[i + 1];
            (void)combined;
        }
        volatile size_t double_access = i * 2;
        (void)double_access;
    }
    // Ensure i is within bounds if exited early due to step of 2
    if (i >= len && i > 0) i = len;
}
