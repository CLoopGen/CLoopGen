#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *message;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = message; *p != '\x00'; p++) {
        if (*p == '\n') {
            *p = ' ';
        }
    }
}
