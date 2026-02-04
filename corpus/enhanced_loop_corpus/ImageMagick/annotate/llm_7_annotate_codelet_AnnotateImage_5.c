#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char *text;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_ptr = text;
    size_t line_counter = number_lines;
    for (; *temp_ptr != '\x00'; temp_ptr++) {
        if (*(temp_ptr) == '\n') {
            line_counter = line_counter + 1;
        }
    }
    number_lines = line_counter;
}
