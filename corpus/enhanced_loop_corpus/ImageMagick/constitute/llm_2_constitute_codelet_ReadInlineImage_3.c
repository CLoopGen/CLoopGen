#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *content;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd character)
    for (p = content; (*p != '/') && (*p != '\x00'); p += 2) {
        if (*(p + 1) == '/' || *(p + 1) == '\x00') {
            p++;
            break;
        }
    }
}
