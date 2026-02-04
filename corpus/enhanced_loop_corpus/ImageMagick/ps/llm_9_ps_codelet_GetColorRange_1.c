#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = start_color; (*p != '-') && (*p != '\x00'); ) {
        if (*p == '(') {
            p++;
            while (*p != ')' && *p != '\x00') {
                p += 2; 
                if (*p == '\x00' || *(p-1) == '-') break;
            }
            if (*p == '\x00') break;
            if (*(p-1) == '-') break;
        } else {
            p++;
        }
    }
}
