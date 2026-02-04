#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *label;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_lines = 1;
    const char *ptr = label;
    for (; *ptr != '\x00'; ptr++) {
        temp_lines += (*ptr == '\n');
    }
    number_lines = temp_lines;
}
