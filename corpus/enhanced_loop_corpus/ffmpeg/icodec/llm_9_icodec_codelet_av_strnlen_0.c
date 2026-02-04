#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Access through pointer with reverse scanning simulation (logically same)
    // Use indirect indexing via forward-to-reverse mapping
    for (i = 0; i < len; i++) {
        size_t rev_i = len - 1 - i;
        if (rev_i < len && !s[rev_i]) {
            // Convert reverse hit into forward index
            i = len - rev_i;
            break;
        }
    }
    // Restore correct i: find first null byte in forward direction
    for (i = 0; i < len && s[i]; i++);
}
