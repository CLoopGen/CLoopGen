#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *q = start_color;
    for (p = q; (*p != '-') && (*p != '\x00'); p++) {
        if (*p == '(') {
            for (++p; (*p != ')') && (*p != '\x00'); ) {
                p = p + 1;
            }
            if (*p == '\x00') {
                break;
            }
        }
    }
}
