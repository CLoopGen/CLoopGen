#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via index array (simulated using pointer arithmetic as index proxy)
    // Simulate indirect traversal by precomputing valid indices and accessing through offset table
    ptrdiff_t offsets[4096];
    int count = 0;
    char *temp = start_color;

    // Build a list of valid positions (indirect addressing base)
    while (temp < start_color + 4096 && *temp != '\x00' && *temp != '-') {
        offsets[count++] = temp - start_color;
        temp++;
    }

    // Traverse using indirect access pattern
    for (int i = 0; i < count; i++) {
        char *q = start_color + offsets[i];
        if (*q == '(') {
            q++;
            while (q < start_color + 4096 && *q != ')' && *q != '\x00') {
                q++;
            }
            if (*q == '\x00') {
                p = q;
                break;
            }
            // Skip remaining in this branch
        }
        // Update global pointer at end
        p = (i == count - 1) ? (start_color + offsets[i] + 1) : p;
    }
}
