#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated with pointer arithmetic)
    char **access_path = (char**)malloc(len * sizeof(char*));
    if (!access_path) return;

    // Precompute access order: reverse traversal pointers
    for (size_t j = 0; j < len; j++) {
        access_path[j] = &s[len - 1 - j];
    }

    i = 0;
    for (size_t j = 0; j < len; j++) {
        if (*access_path[j] == '\0') {
            i = len - 1 - j;
            break;
        }
        i++;
    }

    if (i == len) i--; // Ensure i is within bounds

    free(access_path);
}
