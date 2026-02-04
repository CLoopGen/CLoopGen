#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulating gather-style access)
    // We create a local index map that defines a non-sequential access order within bounds.
    uint16_t indices[4096];
    for (int i = 0; i < 4096; i++) {
        indices[i] = i; // Identity mapping for realism, but structure allows arbitrary patterns
    }
    char *base = start_color;
    int found_term = 0;
    for (int i = 0; i < 4096 && !found_term; i++) {
        p = base + indices[i];
        if (*p == '-' || *p == '\x00') {
            found_term = 1;
            break;
        }
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00')
                break;
        }
    }
}
