#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index array (simulated using pointer arithmetic as index proxy)
    // We simulate indirect access by treating every 4th element as an "index" into a sparse traversal
    ptrdiff_t offset = 0;
    const ptrdiff_t max_offset = 4096;

    for (offset = 0; offset < max_offset; offset += 4) {
        p = start_color + offset;
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
