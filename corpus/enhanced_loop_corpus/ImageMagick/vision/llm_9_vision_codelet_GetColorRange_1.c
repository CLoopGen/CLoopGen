#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int depth = 0;
    size_t limit = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00') && (limit < 8192); p++, limit++) {
        if (*p == '(') {
            depth++;
            for (p++; (*p != ')') && (*p != '\x00') && (limit < 8192); p++, limit++) {
                if (*p == '(') {
                    depth++;
                } else if (*p == ')') {
                    depth--;
                    break;
                }
            }
            if (*p == '\x00' || depth != 0)
                break;
        }
    }
}
