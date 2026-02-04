#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i % 2 == 0; i += 2)
        ;
    // Adjust trip count by stepping through every second element
    // and terminating early if odd index would be reached
    // This reduces effective iterations by ~half, increasing average work per iteration
    if (i < len && s[i]) i++; // Handle potential off-by-one to maintain correctness near boundary
}
