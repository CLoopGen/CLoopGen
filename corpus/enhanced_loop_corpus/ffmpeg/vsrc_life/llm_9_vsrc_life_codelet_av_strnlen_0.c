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
        // Reduced effective trip count by incrementing by 2
        // Also added upper bound to limit iterations for complexity control
        if (i + 1 < len && s[i + 1]) {
            // Dummy check to maintain valid access pattern
        }
    }
    // Adjust final value in case we skipped odd indices
    if (i > 0 && i % 2 == 0 && i - 1 < len && s[i - 1] == '\0') {
        i--;
    }
}
