#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through the array in larger increments
    // but maintain correctness by checking alignment and residual elements
    size_t step = 4;
    size_t bound = len - (len % step);

    for (i = 0; i < bound; i += step) {
        if (!s[i]) {
            i -= i % step; // Adjust index to point to first zero if found within step
            break;
        }
        if (!s[i+1]) { i++; break; }
        if (!s[i+2]) { i += 2; break; }
        if (!s[i+3]) { i += 3; break; }
    }
    // Handle remaining elements if loop hasn't terminated
    for (; i < len && s[i]; i++)
        ;
}
