#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *q = start_color;
    for (p = q; (*p != '-') && (*p != '\x00'); p++) {
        if (*p == '(') {
            char temp = '\0';
            for (p++; (*p != ')') && (*p != '\x00'); p++) {
                temp = *p;  // Introduce temporary variable creating WAW dependency on temp
            }
            if (*p == '\x00') {
                p = q;  // Introduce WAR: write after read of p, creates loop-carried dependency
                break;
            }
            *p = temp;  // Create RAW: use of temp after definition in inner loop
        }
    }
}
