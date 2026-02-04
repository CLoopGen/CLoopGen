#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i]; i++) {
        // Outer loop body is empty, introducing a redundant nested loop that doesn't change logic
        for (size_t j = 0; j < 1; j++) {
            // This inner loop runs exactly once per outer iteration
        }
    }
}
