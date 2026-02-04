#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    for (offset = 0; (start_color[offset] != '-') && (start_color[offset] != '\x00'); offset++) {
        if (start_color[offset] == '(') {
            offset++;
            while ((start_color[offset] != ')') && (start_color[offset] != '\x00')) {
                offset++;
            }
            if (start_color[offset] == '\x00') {
                offset--;
                break;
            }
        }
        p = start_color + offset;
    }
}
