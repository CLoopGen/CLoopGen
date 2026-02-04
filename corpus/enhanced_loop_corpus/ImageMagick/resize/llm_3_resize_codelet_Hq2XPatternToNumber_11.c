#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *pattern;
extern ssize_t i;
extern unsigned int result;
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index mapping table
    static const ssize_t index_map[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Reorders access: even indices first, then odd
    for (i = 7; i >= 0; i--) {
        result += order * (unsigned int)pattern[index_map[i]];
        order *= 2;
    }
}
