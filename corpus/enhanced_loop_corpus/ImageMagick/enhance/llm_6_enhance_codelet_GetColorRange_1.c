#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *q = start_color;
    for (p = start_color; (*p != '-') && (*p != '\x00'); p++) {
        if (*p == '(') {
            for (q = p + 1; (*q != ')') && (*q != '\x00'); q++)
                ;
            p = q; // Update p to skip the content inside parentheses
            if (*p == '\x00')
                break;
        }
    }
}
