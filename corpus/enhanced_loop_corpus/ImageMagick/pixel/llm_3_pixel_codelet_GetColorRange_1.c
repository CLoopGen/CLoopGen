#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an index array (simulating gather-style access)
    // Create a static index map assuming sequential indices accessed indirectly
    static uint16_t indices[4096];
    for (int i = 0; i < 4096; i++) {
        indices[i] = i; // Identity mapping for indirect access (can be randomized or reordered in real use cases)
    }

    char *base = start_color;
    int idx;
    for (idx = 0; (idx < 4096) && (base[indices[idx]] != '-') && (base[indices[idx]] != '\x00'); idx++) {
        if (base[indices[idx]] == '(') {
            idx++; // Move to next index
            while (idx < 4096 && base[indices[idx]] != ')' && base[indices[idx]] != '\x00') {
                idx++;
            }
            if (idx >= 4096 || base[indices[idx]] == '\x00') {
                break;
            }
        }
    }
    // Update global pointer p based on final logical position
    if (idx < 4096)
        p = &base[indices[idx]];
    else
        p = &base[4095]; // Fallback to last valid location
}
