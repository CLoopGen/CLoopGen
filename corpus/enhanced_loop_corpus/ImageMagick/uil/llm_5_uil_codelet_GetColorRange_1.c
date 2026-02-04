#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = start_color; *p != '\x00' && *p != '-'; p++) {
        if (*p == '(') {
            for (p++; (*p != ')' && *p != '\x00'); p++)
                continue;
            if (*p == '\x00') return;
        } else if (*p == '-') {
            break;
        }
    }
}
