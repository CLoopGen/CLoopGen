#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulating gather-style access)
    // We simulate a small indirect access pattern using fixed offset indices
    ptrdiff_t offsets[4096];
    int count = 0;
    char *q = start_color;
    while (q < start_color + 4096 && *q != '\x00') {
        offsets[count++] = q - start_color;
        q++;
    }
    // Now traverse indirectly using the recorded offsets
    for (int i = 0; i < count; i++) {
        p = start_color + offsets[i];
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
