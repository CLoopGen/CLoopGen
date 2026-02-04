#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev = '\0';
    for (p = start_color; (*p != '-') && (*p != '\x00'); p++) {
        if (*p == '(' && prev != '\\') {
            int depth = 1;
            for (p++; depth > 0 && (*p != '\x00'); p++) {
                if (*p == '(') depth++;
                else if (*p == ')') depth--;
            }
            if (*p == '\x00') {
                p--; // Adjust to exit outer loop correctly
                break;
            }
            p--; // Compensate for outer loop increment
        }
        prev = *p;
    }
}
