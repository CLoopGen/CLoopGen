#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *text;
extern  char *p;
extern size_t lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = text; *p != '\x00'; p++) {
        if (*p != '\n') continue;
        lines++;
    }
}
