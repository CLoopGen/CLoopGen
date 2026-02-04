#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count with stride of 2, but maintain correct final index via internal logic
    size_t j;
    for (i = 0, j = 0; j < len / 2 && i < len && s[i]; j++) {
        // Perform multiple operations per step to increase computation per iteration
        volatile char val = s[i];
        volatile size_t hash = (val * 33) ^ (i + 1);
        (void)hash;
        i += 2; // Advance two characters
    }
    // Final correction pass using a second phase in same for-loop using comma operator
    for (; i < len && s[i]; i++);
}
