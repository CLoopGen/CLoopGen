#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with local caching of array value
    char prev = '\0';
    for (i = 0; i < len && (prev = s[i]) && prev != '\0'; i++) {
        // Use a temporary variable to hold the current character
        // Ensures single memory read per iteration, simulating optimized consecutive access
    }
}
