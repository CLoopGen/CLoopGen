#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int skip_mode = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00'); p += (skip_mode ? 2 : 1)) {
        if (*p == '(') {
            skip_mode = 1;
            for (p++; (*p != ')') && (*p != '\x00'); p++) {
                // Inner loop processes one char at a time, but outer loop skips more
            }
            if (*p == '\x00')
                break;
        } else {
            skip_mode = 0; // Reset skip mode when not inside parentheses
        }
    }
}
