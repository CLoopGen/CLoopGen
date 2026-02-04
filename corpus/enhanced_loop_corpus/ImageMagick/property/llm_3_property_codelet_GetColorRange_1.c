#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Index Array (simulated with offset array)
    // Simulate indirect access using a precomputed index map (within bounds)
    static const size_t indices[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // small pattern for example
    const size_t num_indices = sizeof(indices) / sizeof(indices[0]);
    size_t i = 0;
    size_t idx;

    for (; i < 4096; i++) {
        idx = indices[(i % num_indices)];
        p = start_color + ((i + idx) % 4096);

        if (*p == '-' || *p == '\x00')
            break;

        if (*p == '(') {
            p++;
            for (; (p - start_color) < 4096 && (*p != ')') && (*p != '\x00'); p++) {
                // Skip inside parentheses
            }
            if (*p == '\x00' || (p - start_color) >= 4096)
                break;
        }
    }
    // Ensure p remains within valid range
    if (p - start_color >= 4096)
        p = start_color + 4095;
}
