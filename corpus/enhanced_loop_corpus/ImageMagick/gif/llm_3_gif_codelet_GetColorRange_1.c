#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array to simulate pointer chasing
    int indices[4096];
    for (int i = 0; i < 4096; ++i) {
        indices[i] = i; // Simulate indirect addressing order
    }

    for (int j = 0; j < 4096; ) {
        char c = start_color[indices[j]];
        if (c == '-' || c == '\x00') break;

        if (c == '(') {
            j++; // Move to next index after '('
            while (j < 4096) {
                char inner_c = start_color[indices[j]];
                if (inner_c == ')' || inner_c == '\x00') break;
                j++;
            }
            if (j >= 4096 || start_color[indices[j]] == '\x00')
                break;
        } else {
            j++;
        }
    }
}
