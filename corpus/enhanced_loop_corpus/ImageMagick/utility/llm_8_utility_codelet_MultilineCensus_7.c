#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *label;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t count = 0;
    for (number_lines = 1; *(label + count) != '\x00'; count++)
        if (*(label + count) == '\n')
            number_lines++;
}
