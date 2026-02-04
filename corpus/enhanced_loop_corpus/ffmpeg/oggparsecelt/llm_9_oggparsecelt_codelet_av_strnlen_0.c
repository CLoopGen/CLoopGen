#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating every fourth element, then compensate with inner unrolled operations
    size_t limit = (len + 3) / 4;  // Ceiling division to cover all elements in chunks of 4
    for (i = 0; i < limit; i++) {
        size_t base = i * 4;
        if (base < len && s[base]) {
            if (base + 1 < len && s[base + 1]) {
                if (base + 2 < len && s[base + 2]) {
                    if (base + 3 < len && s[base + 3]) {
                        continue;
                    }
                }
            }
        }
        break;
    }
    // Re-map i to actual character index where null or boundary was hit
    for (i = i * 4; i < len && s[i]; i++)
        ;
}
