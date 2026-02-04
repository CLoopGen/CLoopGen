#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    char *current = start_color;
    for (; current < start_color + 4096 && (*current != '-') && (*current != '\x00'); current++) {
        if (*current == '(') {
            for (current++; current < start_color + 4096 && (*current != ')') && (*current != '\x00'); current++) {
                offset++;
            }
            if (*current == '\x00') {
                break;
            }
        }
        offset += (*current != '\x00');
    }
}
