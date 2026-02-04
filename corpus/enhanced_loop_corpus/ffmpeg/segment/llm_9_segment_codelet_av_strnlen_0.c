#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping multiple indices per iteration
    // and include arithmetic complexity via index masking
    for (i = 0; i < len && s[i]; i += 2) {
        // Perform additional arithmetic to increase intensity
        size_t idx1 = (i & ~1U);
        size_t idx2 = idx1 + 1;
        if (idx2 < len && s[idx2] == 0) {
            i++; // Adjust final index if early null found
            break;
        }
    }
}
