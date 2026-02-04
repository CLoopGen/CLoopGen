#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = start_color; (*p != '-') && (*p != '\x00'); ) {
        if (*p == '(') {
            p++;
            int depth = 1;
            for (; (*p != '\x00') && (depth > 0); p++) {
                if (*p == '(') depth++;
                else if (*p == ')') depth--;
            }
            if (*p == '\x00') break;
        } else {
            p++;
        }
    }
}
