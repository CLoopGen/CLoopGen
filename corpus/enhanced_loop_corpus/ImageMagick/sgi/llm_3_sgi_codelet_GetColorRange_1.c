#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array (simulated with pointer arithmetic)
    // Create a virtual index map: access elements in reverse order within segments of 16 bytes
    char *base;
    int offset;
    for (int i = 0; i < 4096; i += 16) {
        base = start_color + i;
        for (int j = 0; j < 16; j++) {
            offset = 15 - j; // Reverse access within each block
            p = base + offset;
            if ((*p == '-') || (*p == '\x00')) return;
            if (*p == '(') {
                for (p++; (*p != ')') && (*p != '\x00'); p++)
                    ;
                if (*p == '\x00')
                    return;
            }
        }
    }
}
