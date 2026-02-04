#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping multiple characters at once
    // Use unrolled-like behavior without actual unrolling for simplicity
    for (i = 0; i + 3 < len; i += 4) {
        if (!s[i])     break;
        if (!s[i + 1]) { i++; break; }
        if (!s[i + 2]) { i += 2; break; }
        if (!s[i + 3]) { i += 3; break; }
    }
    // Handle remaining elements with single-step to maintain correctness
    for (; i < len && s[i]; i++)
        ;
}
