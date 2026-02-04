#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Simulate indirect access using an index map that determines the next position to read.
    // This mimics scenarios where memory is accessed non-sequentially based on a lookup.

    size_t i = 0;
    size_t indices[4096]; // Precomputed indirect access pattern: sequential but via index array
    char *base = start_color;

    // Initialize indirect indices with simple sequential mapping (could be randomized or strided in real use)
    for (i = 0; base[i] != '\x00' && i < 4095; i++) {
        indices[i] = i;
    }
    indices[i] = 4095; // Sentinel

    // Traverse using indirect addressing
    for (i = 0; (base[indices[i]] != '-') && (base[indices[i]] != '\x00'); i++) {
        p = base + indices[i];
        if (*p == '(') {
            p++;
            while ((*p != ')') && (*p != '\x00')) {
                i++;
                if (i >= 4095) break;
                p = base + indices[i];
            }
            if (*p == '\x00')
                break;
        }
    }
}
