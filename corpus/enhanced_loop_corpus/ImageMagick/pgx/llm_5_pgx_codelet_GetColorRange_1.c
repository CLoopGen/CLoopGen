#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char found_close = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00') && !found_close; p++) {
        if (*p == '(') {
            found_close = 1;
            for (++p; *p != '\x00'; p++) {
                if (*p == ')') {
                    found_close = 0;
                    break;
                }
            }
        }
    }
}
