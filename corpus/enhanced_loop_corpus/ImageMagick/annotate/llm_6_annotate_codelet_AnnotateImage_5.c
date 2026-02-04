#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char *text;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_p;
    size_t local_count = 0;
    for (local_p = text; *local_p != '\x00'; local_p++) {
        local_count += (*local_p == '\n');
    }
    number_lines += local_count;
}
