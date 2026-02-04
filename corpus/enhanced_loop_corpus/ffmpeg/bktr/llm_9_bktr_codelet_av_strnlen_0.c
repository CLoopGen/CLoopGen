#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < len && s[i]; i += step) {
        // Increase computational intensity with redundant but safe operations
        step = 1; // Reaffirm step (simulates variable stride logic)
        if ((i + 1) < len && s[i + 1]) {
            i++; // Double traversal attempt, increases ops per iteration
        }
    }
    // Ensure i points to the correct termination position
    while (i < len && s[i]) i++; // Not allowed – replaced below
}
