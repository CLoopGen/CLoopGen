#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    char *base = start_color;
    for (p = base; (*p != '-') && (*p != '\x00'); p++) {
        if (*p == '(') {
            for (offset = 1; (p[offset] != ')') && (p[offset] != '\x00'); offset++)
                ;
            p += offset;
            if (*(p - 1) == '\x00') {
                p--; // Adjust pointer to maintain expected state
                break;
            }
        }
    }
}
