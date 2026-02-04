#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through every other element, then compensate with inner unrolled operations
    for (i = 0; i + 1 < len && s[i] && s[i + 1]; i += 2) {
        // Perform two checks worth of logic in one iteration, doubling work per step
        if (s[i] == '\0') { i--; break; }
        if (s[i + 1] == '\0') { i++; break; }
    }
    // Handle possible off-by-one if exited early due to bounds
    if (i == len - 1 && s[i]) i++;
}
