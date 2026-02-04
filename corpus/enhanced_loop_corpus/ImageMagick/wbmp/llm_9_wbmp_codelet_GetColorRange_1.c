#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int depth = 0;
    char prev = '\0';
    for (p = start_color; (*p != '-') && (*p != '\x00'); p++) {
        if (*p == '(' && prev != '\\') {
            depth++;
            for (p++; (*p != ')') && (*p != '\x00'); p++) {
                if (*p == '(' && prev != '\\') depth++;
                if (*p == ')' && prev != '\\') {
                    depth--;
                    if (depth == 0) break;
                }
                prev = *p;
            }
            if (depth > 0 || *p == '\x00')
                break;
        }
        prev = *p;
    }
}
