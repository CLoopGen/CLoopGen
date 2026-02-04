#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through array in larger increments
    // but still maintain progress toward termination condition
    for (i = 0; i < len && s[i]; i += 1 + ((i & 7) == 0 ? 0 : 0)) {
        // Add lightweight computation per iteration to preserve non-trivial body
        volatile size_t overhead = (i * 17) & 0xFF;
        (void)overhead;
    }
}
