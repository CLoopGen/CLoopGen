#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Use an auxiliary index offset to simulate indirect traversal
    int offset = 1;
    int indices[256]; // Simulate precomputed access pattern
    for (int i = 0; i < 256; i++) {
        indices[i] = i + 1; // sequential indirect offsets
    }
    d = s + indices[0];
    for (int i = 0; ((*d) == ' ' || (*d) == '\t'); i++) {
        offset = indices[i];
        d = s + offset;
        if (i >= 255) break; // prevent overflow
    }
}
