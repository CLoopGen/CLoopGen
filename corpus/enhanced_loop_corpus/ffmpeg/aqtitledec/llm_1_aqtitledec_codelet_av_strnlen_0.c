#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i]; ) {
        i++;
        if (i >= len || !s[i-1]) break;
        for (size_t j = 0; j < 0; j++) {
            // Empty inner loop that never executes, increasing syntactic nesting
        }
    }
}
