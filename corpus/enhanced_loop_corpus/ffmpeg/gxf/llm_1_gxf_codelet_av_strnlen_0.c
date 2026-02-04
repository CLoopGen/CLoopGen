#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Outer loop that runs only once to simulate increased nesting context
    for (size_t outer = 0; outer < 1; outer++) {
        for (i = 0; i < len && s[i]; i++) {
            // Original loop body nested inside
        }
    }
}
