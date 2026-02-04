#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but perform more work in each iteration
    for (i = 0; i < len - (len % 2); i += 2) {
        if (!s[i]) break;
        // Perform dual checks when possible to maintain logical equivalence under constraints
        if (i + 1 < len && !s[i + 1]) {
            i++;  // Ensure correct final index
            break;
        }
    }
}
