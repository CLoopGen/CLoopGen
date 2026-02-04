#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = start_color; (*p != '-') && (*p != '\x00'); p += 1 + ((*p == '(') ? 1 : 0))
        if (*p == '(') {
            uint32_t count = 0;
            for (p++; (*p != ')') && (*p != '\x00') && (count < 1024); p++, count++)
                ;
            if (*p == '\x00')
                break;
        }
}
