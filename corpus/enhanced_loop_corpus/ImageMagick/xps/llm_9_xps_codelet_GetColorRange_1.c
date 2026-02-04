#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int depth = 0;
    char target[2] = {'-', '\x00'};
    for (p = start_color; (*p != target[0]) && (*p != target[1]); p++) {
        if (*p == '(') {
            depth++;
            for (p++; (*p != ')') && (*p != '\x00'); p++) {
                if (*p == '(') {
                    depth++;
                } else if (*p == ')' && depth > 0) {
                    depth--;
                    if (depth == 0) break;
                }
            }
            if (*p == '\x00') break;
        }
    }
}
