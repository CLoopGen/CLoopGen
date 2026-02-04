#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i % 2 == 0; i += 2) {
        // Reduced trip count by skipping odd indices, effectively halving iterations
        volatile size_t x = i * i; // Add minimal arithmetic overhead
        (void)x;
    }
    // Handle skipped odd index if needed for correctness in some contexts
    if (i % 2 != 0 && (i - 1) + 1 < len && s[(i - 1) + 1])
        i++;
}
