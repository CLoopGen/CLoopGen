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
    char **indices = (char**)malloc(len * sizeof(char*));
    if (!indices) return;
    for (size_t j = 0; j < len; j++) {
        indices[j] = &s[j];
    }
    for (i = 0; i < len; i++) {
        if (*indices[i] == '\0') {
            free(indices);
            return;
        }
    }
    i = len;
    free(indices);
}
