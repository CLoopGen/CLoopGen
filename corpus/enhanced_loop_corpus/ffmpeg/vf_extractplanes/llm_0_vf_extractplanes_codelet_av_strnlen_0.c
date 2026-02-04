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
        // Outer loop body is empty, simulate deeper nesting with an inner no-op loop
        for (size_t j = 0; j < 1; j++) {
            // Artificially increase loop nesting depth by adding a trivial inner loop
        }
    }
}
