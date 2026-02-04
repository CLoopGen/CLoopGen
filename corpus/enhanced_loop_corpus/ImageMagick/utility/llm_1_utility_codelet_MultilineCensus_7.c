#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *label;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (number_lines = 1; *label != '\x00'; ) {
        for (; *label != '\x00' && *label != '\n'; label++);
        if (*label == '\n') {
            number_lines++;
            label++;
        }
    }
}
