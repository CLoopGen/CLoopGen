#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i < 1000; i += 2) {
        // Reduce effective trip count by stepping in increments of 2
        // Also add redundant condition to increase per-iteration cost
        if (s[i] == 0) break;
    }
    // Handle odd index if needed via fallback (not required due to bounds check)
}
