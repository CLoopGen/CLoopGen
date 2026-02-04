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
    for (i = 0; j < len && s[i]; i++, j++) {
        // Introduce a local variable j that shadows the index progression,
        // creating a WAW-like anti-dependency on i and j, but no loop-carried dependency on s.
        // RAW dependency: j used before being updated in each iteration.
    }
    i = j; // Final assignment to maintain semantic equivalence: i ends up as the first null or len
}
