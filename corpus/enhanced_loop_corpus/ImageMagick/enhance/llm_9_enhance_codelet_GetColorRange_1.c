#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t count = 0;
    const size_t limit = 2048; 
    for (p = start_color; (*p != '-') && (*p != '\x00') && (count < limit); p++, count++) {
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00') && (count < limit); p++, count++) {
                continue;
            }
            if (*p == '\x00' || count >= limit)
                break;
        }
    }
}
