#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count by stepping through every other element
    // and using early unrolling to maintain correctness for odd/even lengths
    for (i = 0; i < len - 1 && s[i] && s[i + 1]; i += 2)
        ;
    // Handle case where loop ended prematurely due to step size
    if (i < len && s[i]) i++;
}
