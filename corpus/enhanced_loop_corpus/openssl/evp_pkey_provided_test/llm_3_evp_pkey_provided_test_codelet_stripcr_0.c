#include <stdio.h>

#include <inttypes.h>

extern char *buf;
extern size_t *len;
extern size_t i;
extern char *curr;
extern char *writ;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Access via Index Array (simulate indirect memory access pattern)
    // Create a local index map to access buffer indirectly, filtering '\r' during traversal
    size_t indices[*len];
    size_t valid_count = 0;

    // Build indirect access list (skip '\r' positions)
    for (i = 0, curr = buf; i < *len; i++, curr++) {
        if (*curr != '\r') {
            indices[valid_count++] = i;
        } else {
            (*len)--;
        }
    }

    // Use indirect indexing to rewrite buffer
    writ = buf;
    for (i = 0; i < valid_count; i++) {
        curr = buf + indices[i];  // Indirect pointer access
        if (curr != writ)
            *writ = *curr;
        writ++;
    }
}
