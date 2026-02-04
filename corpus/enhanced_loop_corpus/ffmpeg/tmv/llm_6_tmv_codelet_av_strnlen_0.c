#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; j < len && s[j]; i++, j++) {
        // Introduce a new induction variable 'j' that removes direct loop-carried dependency on 'i' for indexing
        // Original use of 'i' is now split: 'i' counts iterations, 'j' accesses memory
        // This creates a WAW-like independence between address calculation and iteration count
    }
}
