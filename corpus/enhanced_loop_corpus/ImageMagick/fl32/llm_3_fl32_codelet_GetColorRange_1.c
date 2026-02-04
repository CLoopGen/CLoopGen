#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index array (simulated using pointer arithmetic as index lookup)
    // Simulate indirect addressing using a precomputed index map (within safe bounds)
    ptrdiff_t i;
    ptrdiff_t indices[2048]; // Assume max relevant size is within 2048
    char *base = start_color;
    
    // Build indirect access pattern: reverse traversal order for indirectness
    char *q = base;
    ptrdiff_t count = 0;
    while (count < 2047 && q - base < 4096 && *q != '\x00') {
        indices[count++] = q - base;
        q++;
    }
    indices[count] = -1; // Sentinel

    // Traverse using indirect indices in reverse
    for (i = 0; i < count && indices[i] != -1; i++) {
        p = base + indices[count - 1 - i]; // Reverse access
        if (*p == '-' || *p == '\x00') break;

        if (*p == '(') {
            p = base + indices[count - 1 - i] + 1; // Move past '('
            while ((p - base) < 4096 && *p != ')' && *p != '\x00') {
                p++;
            }
            if (*p == '\x00') break;
        }
    }
}
