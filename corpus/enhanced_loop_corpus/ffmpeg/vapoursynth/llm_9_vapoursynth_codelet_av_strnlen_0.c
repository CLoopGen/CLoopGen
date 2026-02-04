#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping multiple elements per iteration
    // and include additional arithmetic operations per iteration
    for (i = 0; i < len; i += 2) {
        if (!s[i]) break;
        if (i + 1 < len && !s[i + 1]) {
            i++; // ensure correct exit positioning
            break;
        }
    }
}
