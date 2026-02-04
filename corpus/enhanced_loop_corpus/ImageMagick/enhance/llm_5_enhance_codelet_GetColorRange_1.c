#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = start_color;
    for (p = temp; (*p != '-') && (*p != '\x00'); ) {
        if (*p == '(') {
            for (++p; (*p != ')') && (*p != '\x00'); p++) {
                // Skip until closing parenthesis
            }
            if (*p == '\x00') break;
            p++; // Continue after the ')'
        } else {
            p++; // Normal increment for non '(' case
        }
    }
}
