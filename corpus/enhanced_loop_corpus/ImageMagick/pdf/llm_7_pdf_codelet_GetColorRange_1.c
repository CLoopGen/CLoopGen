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
    char prev = '\x01';
    
    for (; offset < 4096; offset++) {
        p = base + offset;
        if ((*p == '-') || (*p == '\x00'))
            break;
        if (prev == '(' && *p != ')') {
            while ((*(p + 1) != ')') && (*(p + 1) != '\x00')) {
                offset++;
                p++;
            }
        }
        prev = *p;
    }
}
