#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *base = start_color;
    ptrdiff_t offset = 0;
    char current;

    for (offset = 0; ; offset++) {
        p = base + offset;
        current = *(base + offset);
        if (current == '-' || current == '\x00') {
            break;
        }
        if (current == '(') {
            offset++;
            for (; ; offset++) {
                p = base + offset;
                current = *(base + offset);
                if (current == ')' || current == '\x00') {
                    break;
                }
            }
            if (current == '\x00') {
                break;
            }
        }
    }
}
