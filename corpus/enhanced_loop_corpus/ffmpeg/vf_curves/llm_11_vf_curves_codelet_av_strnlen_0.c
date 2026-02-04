#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using pointer array
    char **ptrs = (char**)malloc(len * sizeof(char*));
    if (!ptrs) {
        for (i = 0; i < len && s[i]; i++)
            ;
        return;
    }

    for (i = 0; i < len; i++) {
        ptrs[i] = &s[i];
    }

    for (i = 0; i < len; i++) {
        if (!*ptrs[i])
            break;
    }

    i = (i < len) ? (ptrs[i] - s) : len;

    free(ptrs);
}
