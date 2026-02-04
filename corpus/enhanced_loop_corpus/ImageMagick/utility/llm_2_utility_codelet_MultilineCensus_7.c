#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *label;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (number_lines = 1, i = 0; label[i] != '\x00'; i++)
        if (label[i] == '\n')
            number_lines++;
}
