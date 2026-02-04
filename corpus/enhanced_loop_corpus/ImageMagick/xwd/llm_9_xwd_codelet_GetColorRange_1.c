#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int depth = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00'); p++) {
        if (*p == '(') {
            depth++;
            while (depth > 0) {
                p++;
                if (*p == '\x00')
                    return;
                if (*p == '(')
                    depth++;
                else if (*p == ')')
                    depth--;
            }
        }
    }
}
