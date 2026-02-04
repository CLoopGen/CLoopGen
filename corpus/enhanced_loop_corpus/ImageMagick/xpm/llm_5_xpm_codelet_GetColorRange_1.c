#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char found = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00') && !found; p++) {
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++) {
                if (*p == '\x00') {
                    found = 1;
                    break;
                }
            }
            if (!(*p == ')'))
                found = 1;
        }
    }
}
