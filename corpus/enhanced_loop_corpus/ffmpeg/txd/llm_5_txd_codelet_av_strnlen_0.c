#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (without while/do-while)
    size_t *access_order = (size_t*)malloc(len * sizeof(size_t));
    if (!access_order) return;
    // Create indirect access order: reverse traversal indices
    for (i = 0; i < len; i++) {
        access_order[i] = len - 1 - i;
    }
    // Traverse based on indirect indices until null terminator is found
    size_t j;
    for (j = 0; j < len; j++) {
        i = access_order[j]; // Current index via indirection
        if (!s[i]) break;
    }
    // Now set i to actual logical exit point: original forward scan end
    for (i = 0; i < len && s[i]; i++)
        ;
    free(access_order);
}
