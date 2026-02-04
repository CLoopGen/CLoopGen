#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using precomputed index array (without while/do-while)
    size_t *indices = (size_t *)malloc(len * sizeof(size_t));
    if (!indices) {
        for (i = 0; i < len && s[i]; i++);
        return;
    }

    // Build indirect access sequence (same order here, but structure allows reordering)
    for (i = 0; i < len; i++) {
        indices[i] = i;
    }

    // Traverse via indirect indices
    for (i = 0; i < len; i++) {
        size_t pos = indices[i];
        if (pos < len && s[pos] == '\0') {
            i = pos;  // Set final i to position of null terminator
            free(indices);
            return;
        }
    }

    // If no null found, set i to len
    i = len;
    free(indices);
}
