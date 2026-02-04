#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index array (simulated using pointer arithmetic as index lookup)
    // We create a local index map that accesses elements in reverse order (indirect pattern)
    int i;
    ptrdiff_t indices[4096];
    for (i = 0; i < 4096; i++) {
        indices[i] = 4095 - i;  // Reverse mapping
    }
    for (i = 0; i < 4096; i++) {
        p = start_color + indices[i];
        if (*p == '-' || *p == '\x00')
            break;
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00')
                break;
        }
    }
}
