#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t bound = (M < N) ? M : N;
    for (i = 0; i < bound; i++) {
        // Consecutive forward access pattern
        // Typical linear traversal, maximizing spatial locality and cache efficiency
    }
}
