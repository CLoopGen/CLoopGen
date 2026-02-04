#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step;
    for (p = start_color; (*p != '-') && (*p != '\x00'); ) {
        step = 1;
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++) {
                step = 2;
                if (*(p + 1) == ')') break;
            }
            if (*p == '\x00') break;
        }
        p += step;
    }
}
