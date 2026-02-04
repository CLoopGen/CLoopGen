#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an index array (simulating gather access)
    // Create a local index mapping for indirect traversal within bounds
    int indices[4096];
    int count = 0;
    // Populate linear indices, could be randomized or reordered in real use cases
    for (int i = 0; i < 4096; i++) {
        indices[count++] = i;
    }

    char *base = start_color;
    for (int i = 0; i < count; i++) {
        char *ptr = base + indices[i];
        if (*ptr == '-' || *ptr == '\x00') {
            p = ptr;
            break;
        }
        if (*ptr == '(') {
            char *inner_ptr = ptr + 1;
            for (; inner_ptr < start_color + 4096 && *inner_ptr != ')' && *inner_ptr != '\x00'; inner_ptr++) {
                // Scan forward for closing ')'
            }
            if (*inner_ptr == '\x00') {
                p = inner_ptr;
                break;
            }
            // Skip past the handled group by updating outer index
            // Simulate effect by ensuring future indices skip this block if needed
        }
        p = ptr; // Maintain global pointer update
    }
}
