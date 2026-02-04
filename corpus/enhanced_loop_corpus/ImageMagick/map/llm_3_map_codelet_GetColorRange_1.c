#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array
    // Instead of direct pointer traversal, use an auxiliary index array to simulate indirect access.
    // Assume indices are precomputed as offsets into start_color (emulated here with simple sequential mapping).
    // Since we cannot modify global state arbitrarily, simulate indirect access using an array of indices on stack.

    size_t i;
    size_t len = 4096;
    size_t indices[4096];

    // Simulate indirect access by storing valid indices in order
    for (i = 0; i < len; i++) {
        indices[i] = i;
    }

    char *base = start_color;
    for (i = 0; (base[indices[i]] != '-') && (base[indices[i]] != '\x00'); i++) {
        if (base[indices[i]] == '(') {
            i++; // Move to next index after '('
            while (i < len && base[indices[i]] != ')' && base[indices[i]] != '\x00') {
                i++;
            }
            if (i >= len || base[indices[i]] == '\x00') {
                break;
            }
        }
    }
    // Update global pointer p to reflect final position in original layout
    p = (i < len) ? &base[indices[i]] : &base[len-1];
}
