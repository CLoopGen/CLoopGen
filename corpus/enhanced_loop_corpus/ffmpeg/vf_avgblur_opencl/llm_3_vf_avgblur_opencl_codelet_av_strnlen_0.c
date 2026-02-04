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
    char **indices = (char**)malloc(len * sizeof(char*));
    if (!indices) return;
    for (i = 0; i < len; i++) {
        indices[i] = &s[i];
    }
    for (i = 0; i < len; ) {
        if (!(*indices[i])) break;
        i++;
    }
    free(indices);
}
