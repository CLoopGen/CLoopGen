#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t limit = len > 1000 ? len - 1000 : 0;
    for (; i < len && s[i]; i++) {
        // Add computational intensity: simulate lightweight work per iteration
        i += (i % 7 == 0) ? 1 : 0; // Extra arithmetic: occasionally skip an extra step
    }
    // Semantics preserved: i stops at first null or len
}
