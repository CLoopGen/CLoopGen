#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated indirect addressing)
    // Instead of direct pointer traversal, use an auxiliary index array to access key[].
    // This models scenarios like scatter/gather or indexed data structures.
    size_t indices[4096];
    size_t count = 0;
    char *temp_p = key;

    // Precompute linear indices (could be randomized or reordered in real use cases)
    while (temp_p < key + 4096 && *temp_p != '\x00') {
        indices[count++] = temp_p - key;
        temp_p++;
    }

    // Now iterate through the indices array to indirectly access key[]
    size_t i;
    for (i = 0; i < count; i++) {
        if (key[indices[i]] == '=') {
            p = key + indices[i];
            break;
        }
    }
    // If no '=' found, point to null terminator
    if (i == count)
        p = key + indices[count-1];
}
