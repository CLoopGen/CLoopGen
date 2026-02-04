#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *q = start_color;
    int skip_mode = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00'); p++) {
        if (*p == '(') {
            skip_mode = 1;
        }
        if (skip_mode) {
            for (char *r = p; (*r != ')') && (*r != '\x00'); r++) {
                p = r;
            }
            if (*p == '\x00') {
                break;
            }
            skip_mode = 0;
        }
    }
    if (skip_mode) p = q;
}
