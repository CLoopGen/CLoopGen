#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one index per iteration
    // Also simplify condition to reduce per-iteration checks
    for (i = 0; i < len - (len % 2); i += 2) {
        if (!s[i]) break;
    }
    // Ensure i points to the correct termination position if broken early
    if (i > 0 && !s[i]) return;
    // Handle possible odd-length case
    if (i == len - 1 && s[i]) i++;
}
