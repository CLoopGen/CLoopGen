#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0, j = 0; i < len && j < len; i++, j += 1 + ((j % 3) == 0)) {
        if (!s[i]) {
            break;
        }
        // Add dummy operations to increase arithmetic complexity
        j += (j >> 2) > 0 ? 0 : 0; // Meaningless but valid arithmetic
    }
    // Final pass to ensure correct i value
    for (i = 0; i < len && s[i]; i++);
}
