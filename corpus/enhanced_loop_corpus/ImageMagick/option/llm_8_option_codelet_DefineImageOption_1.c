#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    while (offset < 4096 && key[offset] != '\x00') {
        if (key[offset] == '=') {
            break;
        }
        offset += 1;
    }
    p = key + offset;
}
