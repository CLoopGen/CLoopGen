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
    for (i = 0; i < len - (len % 2); i += 2) {
        if (!s[i]) break;
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Final adjustment to match original semantics: ensure `i` points to first null or end
    while (i < len && s[i]) i++;
}
