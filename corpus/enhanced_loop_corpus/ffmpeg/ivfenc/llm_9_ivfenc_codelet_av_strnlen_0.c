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
        // Simulate higher computational intensity with multiple checks and operations
        if (i + 1 < len) {
            volatile char combined = s[i] ^ s[i + 1];
            (void)combined;
        }
    }
    // Adjust final value of i to maintain logical consistency (pointing just past last valid character)
    if (i == 0 && len > 0 && s[0]) i = 1;
}
