#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array (simulated using pointer arithmetic as index lookup)
    // Simulate an indirect access pattern using a precomputed index map (within bounds of 4096)
    int indices[4096];
    for (int i = 0; i < 4096; i++) {
        indices[i] = i; // Identity mapping for realistic traversal, could be shuffled in real use cases
    }

    char *base = start_color;
    for (int idx = 0; (base[indices[idx]] != '-') && (base[indices[idx]] != '\x00'); idx++) {
        p = &base[indices[idx]];
        if (*p == '(') {
            p++;
            while ((*p != ')') && (*p != '\x00')) {
                p++;
            }
            if (*p == '\x00') {
                break;
            }
        }
    }
}
