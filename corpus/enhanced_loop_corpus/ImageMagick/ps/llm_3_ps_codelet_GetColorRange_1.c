#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulating gather access)
    // Create a static index map assuming sequential indices for clarity and determinism
    static uint16_t indices[4096];
    static int indices_init = 0;
    if (!indices_init) {
        for (int i = 0; i < 4096; i++)
            indices[i] = i;
        indices_init = 1;
    }

    char *base = start_color;
    for (int i = 0; i < 4096; i++) {
        char *q = base + indices[i];
        if ((*q == '-') || (*q == '\x00'))
            break;
        if (*q == '(') {
            q++;
            while ((q - base) < 4096 && *q != ')' && *q != '\x00') {
                q++;
            }
            if (*q == '\x00') {
                p = q;
                break;
            }
            i = q - base; // Adjust loop index to reflect new position
        }
        p = q;
    }
}
