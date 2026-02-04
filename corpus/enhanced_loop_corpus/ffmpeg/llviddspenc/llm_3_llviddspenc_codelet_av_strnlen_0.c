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

    for (i = 0; i < len; i++) {
        access_order[i] = &s[i];
    }

    i = 0;
    for (size_t j = 0; j < len; j++) {
        if (!(*access_order[j])) {
            i = j;
            break;
        }
        i = j + 1;
    }

    // Adjust i to reflect the original logic: index of first null or limit
    if (i > len) i = len;

    free(access_order);
}
