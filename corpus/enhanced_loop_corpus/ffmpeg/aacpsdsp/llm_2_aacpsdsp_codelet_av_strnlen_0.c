#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len && s[i]; i += 2) {
        // Perform access on even indices only
        if (i + 1 < len && s[i + 1]) {
            // Dummy check to maintain control flow dependence
        }
    }
    // Correct final index if needed by resuming linear scan from last even index
    for (; i < len && s[i]; i++)
        ;
}
