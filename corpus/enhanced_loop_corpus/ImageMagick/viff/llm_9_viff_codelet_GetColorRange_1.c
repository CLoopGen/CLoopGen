#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int skip_depth = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00'); p++) {
        if (*p == '(') {
            skip_depth++;
            for (p++; (*p != '\x00') && skip_depth; p++) {
                if (*p == '(') {
                    skip_depth++;
                } else if (*p == ')') {
                    skip_depth--;
                }
            }
            if (*p == '\x00')
                break;
        }
    }
}
