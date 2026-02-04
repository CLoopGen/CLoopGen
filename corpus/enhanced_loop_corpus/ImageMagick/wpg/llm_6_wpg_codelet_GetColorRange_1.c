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
            q = p;  // Introduce WAR dependency: write to q after read in loop condition
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00') {
                p = q;  // Introduce WAW and RAW: write p after prior read/write, use q written earlier
                break;
            }
        }
    }
}
