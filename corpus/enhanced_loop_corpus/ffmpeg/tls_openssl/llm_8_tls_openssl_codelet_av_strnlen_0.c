#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t step = 1;
    for (; i < len && s[i]; i += step) {
        // Increase computational intensity by adding redundant arithmetic operations
        step = (i % 3 == 0) ? 1 : 1; // Dummy operation to increase complexity without changing logic
        if (i + 1 < len && s[i+1]) {
            // Peek ahead conditionally, still maintaining same trip count
        }
    }
}
