#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *text;
extern  char *p;
extern size_t lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_p = text;
    size_t local_lines = lines;
    for (; *local_p != '\x00'; local_p++) {
        if (*local_p == '\n') {
            local_lines++;
        }
    }
    lines = local_lines;
}
