#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an index array (simulated using pointer arithmetic as index table)
    // Create a simulated "index map" on stack (small fixed-size for safety)
    int indices[512];
    int count = 0;
    char *temp = start_color;

    // Precompute valid indices where characters are not '-' or '\0', up to limit
    while (*temp != '\0' && count < 512) {
        indices[count++] = temp - start_color; // Store offset
        temp++;
    }

    // Now iterate through the precomputed indices (indirect access pattern)
    for (int i = 0; i < count; i++) {
        char c = start_color[indices[i]];
        if (c == '-') break;
        if (c == '(') {
            // Manually scan forward from current index until ')' or '\0'
            int pos = indices[i] + 1;
            while (pos < 4096 && start_color[pos] != '\x00') {
                if (start_color[pos] == ')') {
                    p = &start_color[pos]; // Update global p
                    break;
                }
                pos++;
            }
            if (pos >= 4096 || start_color[pos] == '\x00') {
                p = &start_color[pos];
                break;
            }
        }
        p = &start_color[indices[i]]; // Update p to current accessed location
    }
}
