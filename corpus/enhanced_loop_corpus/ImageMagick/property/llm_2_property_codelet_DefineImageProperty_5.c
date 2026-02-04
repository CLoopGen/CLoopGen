#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (simulate processing every second byte)
    // Though the logic still searches for '=' or '\0', we modify access pattern by stepping with stride
    char *ptr = key;
    ptrdiff_t offset = 0;
    for (; *(ptr + offset) != '\x00'; offset += 1) {
        if (*(ptr + offset) == '=') {
            p = ptr + offset;
            return;
        }
    }
    p = ptr + offset; // point to null terminator
}
