#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int depth = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00') && (p < start_color + 4096); p += (depth > 0) ? 1 : 2) {
        if (*p == '(') {
            depth++;
            continue;
        }
        if (*p == ')' && depth > 0) {
            depth--;
            continue;
        }
        if (depth == 0 && (*p == ' ' || *p == '\t'))
            continue;
    }
    if (depth > 0 && p >= start_color + 4096)
        p = start_color + 4096;
}
