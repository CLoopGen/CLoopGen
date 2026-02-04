#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int skip_mode = 0;
    int depth = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00'); p++) {
        if (*p == '(') {
            skip_mode = 1;
            depth = 1;
            for (p++; (*p != '\x00') && depth; p++) {
                if (*p == '(') depth++;
                else if (*p == ')') depth--;
            }
            if (*p == '\x00') break;
            if (depth == 0) p--; 
            skip_mode = 0;
        }
    }
}
