#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array (simulated with pointer array)
    // Create a local index mapping for indirect traversal (every 3rd position, then reverse order segment)
    char *indices[4096];
    int count = 0;
    for (int i = 0; i < 4096; i += 3) {
        indices[count++] = &start_color[i];
    }
    // Reverse part of the access pattern to introduce non-sequential behavior
    for (int j = count - 1; j >= 0; j--) {
        p = indices[j];
        if (*p == '\x00' || *p == '-')
            break;
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00')
                break;
        }
    }
}
