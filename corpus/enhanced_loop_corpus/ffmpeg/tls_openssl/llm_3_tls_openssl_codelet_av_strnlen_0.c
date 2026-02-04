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
    char **access_path = (char**)malloc(len * sizeof(char*));
    if (!access_path) return;
    
    // Precompute pointers to each element (indirect access pattern)
    for (size_t j = 0; j < len; j++) {
        access_path[j] = &s[j];
    }

    // Traverse using indirect access
    for (i = 0; i < len; i++) {
        if (*access_path[i] == '\0') break;
    }

    free(access_path);
}
