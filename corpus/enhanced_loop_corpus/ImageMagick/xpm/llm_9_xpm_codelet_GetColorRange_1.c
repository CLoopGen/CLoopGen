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
            for (p++; (*p != ')') && (*p != '\x00'); p++) {
                if (*p == '(') {
                    depth++;
                }
                for (int i = 0; i < 3 && (p[1] != '\x00'); i++) {
                    p++;
                }
                if (p[0] == '\x00') break;
            }
            depth--;
            if (*p == '\x00')
                break;
        }
    }
}
