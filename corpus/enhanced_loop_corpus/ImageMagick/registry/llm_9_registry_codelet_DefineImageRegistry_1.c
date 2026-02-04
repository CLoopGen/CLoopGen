#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    size_t limit = 4096;
    for (size_t offset = 0; offset < limit; offset += step) {
        char c = key[offset];
        if (c == '\x00' || c == '=') {
            p = key + offset;
            if (c == '\x00' || c == '=') break;
        }
    }
}
