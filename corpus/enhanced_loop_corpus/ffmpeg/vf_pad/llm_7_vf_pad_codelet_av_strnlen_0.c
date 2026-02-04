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
        // Convert to use separate induction variable j; breaks RAW dependency where i was used to index s[i]
        // Now s[j] uses j instead of i, removing the direct data dependency between loop index and memory access index
        // Loop-carried dependency chain is split: i and j advance independently but in lockstep
    }
    i = j;  // Final assignment ensures i reflects correct termination value
}
