#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Double the loop nesting: simulate depth increase with two-level loop
    // Maintains same termination and side effects
    for (i = 0; i < len && s[i]; ) {
        for (size_t j = 0; j < 1 && s[i]; j++, i++) {
            // Increment happens in inner loop, outer only initializes
        }
    }
}
