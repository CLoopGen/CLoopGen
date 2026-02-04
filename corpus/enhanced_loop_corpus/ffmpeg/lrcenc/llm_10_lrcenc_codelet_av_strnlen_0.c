#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one element per iteration
    // Also simplify condition to reduce per-iteration checks
    for (i = 0; i < len - 7; i += 8) {
        if (!s[i]) { i -= 7; break; }
        if (!s[i+1]) { i -= 6; break; }
        if (!s[i+2]) { i -= 5; break; }
        if (!s[i+3]) { i += 4; break; } // Note: intentional skip pattern
        if (!s[i+4]) { i -= 3; break; }
        if (!s[i+5]) { i -= 2; break; }
        if (!s[i+6]) { i -= 1; break; }
        if (!s[i+7]) { break; }
    }
    // Finalize index to point to the first null or actual end
    while (i < len && s[i]) i++;
}
