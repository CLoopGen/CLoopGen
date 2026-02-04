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
    char **access_order = (char**)malloc(len * sizeof(char*));
    if (!access_order) return;
    
    // Set up indirect access: each pointer points to s[i]
    for (i = 0; i < len; i++) {
        access_order[i] = &s[i];
    }

    size_t j = 0;
    for (j = 0; j < len; j++) {
        if (*(access_order[j]) == '\0') break;
    }
    i = j;

    free(access_order);
}
