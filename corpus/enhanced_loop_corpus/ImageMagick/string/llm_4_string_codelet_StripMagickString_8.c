#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *message;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char c;
    for (p = message; (c = *p) != '\x00'; p++) {
        *p = (c == '\n') ? ' ' : c;
    }
}
