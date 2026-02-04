#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = start_color; (*p != '-') && (*p != '\x00') && (*(p + 1) != '\x00'); p += 2) {
        if (*p == '(' || *(p + 1) == '(') {
            char found_close = 0;
            for (p++; (*p != ')') && (*p != '\x00'); p++) {
                if (*p == '\\') {
                    p++;
                    if (*p == '\x00') break;
                }
                if (*p == ')') {
                    found_close = 1;
                }
            }
            if (!found_close)
                break;
        }
    }
}
