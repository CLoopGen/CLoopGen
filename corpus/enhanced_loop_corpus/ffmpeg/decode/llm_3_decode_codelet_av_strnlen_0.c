#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate pointer array
    char **access_pattern = (char**)malloc(len * sizeof(char*));
    if (!access_pattern) return; // Handle allocation failure

    // Build indirect access pattern: each element points to s[i]
    for (size_t j = 0; j < len; j++) {
        access_pattern[j] = &s[j];
    }

    // Traverse using indirect pointers
    for (i = 0; i < len; i++) {
        if (!(*access_pattern[i])) break;
    }

    free(access_pattern);
}
