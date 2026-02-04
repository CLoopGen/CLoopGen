#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by processing multiple elements per iteration
    // and increase arithmetic operations per iteration
    for (i = 0; i < len; i += 2) {
        if (!s[i]) break;
        if (i + 1 < len && !s[i + 1]) {
            i++; // Ensure correct termination point
            break;
        }
        // Add computational overhead: simulate extra work
        volatile size_t dummy = i * i + 3 * i - 2;
        (void)dummy;
    }
}
