#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index array (simulated using pointer arithmetic)
    // Create local index mapping to simulate indirect traversal
    ptrdiff_t indices[4096];
    char *temp = start_color;
    ptrdiff_t count = 0;

    // Precompute indices for valid positions (non-null and not '-' terminal)
    while (temp < start_color + 4096 && *temp != '-' && *temp != '\x00') {
        indices[count++] = temp - start_color;
        temp++;
    }

    // Traverse using indirect indexing
    for (ptrdiff_t i = 0; i < count; i++) {
        char *q = start_color + indices[i];
        if (*q == '(') {
            q++; // Move past '('
            while (q < start_color + 4096 && *q != ')' && *q != '\x00') {
                q++;
            }
            if (*q == '\x00') {
                p = q;
                break;
            }
            // Skip remaining in this branch, but continue outer loop
        }
        // Update global pointer on each iteration to maintain state
        p = q;
    }
}
