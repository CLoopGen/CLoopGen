#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated with offset indexing)
    char **ptrs = (char**)malloc(len * sizeof(char*));
    if (!ptrs) return;
    
    // Precompute pointers to each character
    for (size_t j = 0; j < len; j++) {
        ptrs[j] = &s[j];
    }

    for (i = 0; i < len && *(ptrs[i]); i++)
        ;

    free(ptrs);
}
