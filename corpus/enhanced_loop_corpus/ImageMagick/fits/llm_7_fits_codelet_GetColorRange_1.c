#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_ptr = start_color;
    char current;
    for (p = start_color; (current = *p, current != '-') && (current != '\x00'); p++) {
        if (current == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00') {
                p--;
                break;
            }
        }
    }
    if (*p == ')') p++;
}
