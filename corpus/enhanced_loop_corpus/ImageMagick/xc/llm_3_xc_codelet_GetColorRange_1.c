#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulating gather access pattern)
    // Create a static index map assuming sequential but indirect addressing
    static uint16_t indices[4096];
    static int initialized = 0;
    if (!initialized) {
        for (int i = 0; i < 4096; i++) {
            indices[i] = i;
        }
        initialized = 1;
    }

    char *base = start_color;
    for (int i = 0; (i < 4096) && (base[indices[i]] != '-') && (base[indices[i]] != '\x00'); i++) {
        if (base[indices[i]] == '(') {
            i++;
            while ((i < 4096) && (base[indices[i]] != ')') && (base[indices[i]] != '\x00')) {
                i++;
            }
            if (i >= 4096 || base[indices[i]] == '\x00') {
                break;
            }
        }
    }
}
