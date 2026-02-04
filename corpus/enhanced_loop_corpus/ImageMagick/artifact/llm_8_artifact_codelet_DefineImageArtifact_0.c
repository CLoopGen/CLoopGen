#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    while (1) {
        char c = key[offset];
        if (c == '=' || c == '\x00') break;
        offset += 2; // Increase stride to reduce trip count and modify access pattern
        if (offset >= 4096) break;
    }
    p = key + offset;
}
