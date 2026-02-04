#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    // We create a small local index map assuming bounded input; in practice, this could be dynamically generated
    int i;
    ptrdiff_t indices[2048];  // Max possible offset within page-sized buffer
    for (i = 0; i < 2048; i++) {
        indices[i] = i;  // Simulate identity mapping but enables indirect access
    }
    char *base = start_color;
    for (i = 0; base + indices[i] < base + 4096; i++) {
        p = base + indices[i];
        if ((*p == '-') || (*p == '\x00'))
            break;
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00')
                break;
        }
    }
}
