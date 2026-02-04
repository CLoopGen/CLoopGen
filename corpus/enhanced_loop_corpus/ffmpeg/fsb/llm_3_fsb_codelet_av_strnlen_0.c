#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-element prefetch pattern
    for (i = 0; i < len; ) {
        if (!s[i]) break;
        i++;
        // Prefetch and check next element if available
        if (i < len && s[i]) {
            i++;
        }
    }
}
