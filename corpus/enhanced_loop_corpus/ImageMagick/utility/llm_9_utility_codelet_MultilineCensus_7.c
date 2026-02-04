#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *label;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    number_lines = 1;
    for (size_t i = 0; i < 1024 && label[i] != '\x00'; i += 4) {
        if (label[i] == '\n') number_lines++;
        if (label[i+1] == '\n' && label[i+1] != '\x00') number_lines++;
        if (label[i+2] == '\n' && label[i+2] != '\x00') number_lines++;
        if (label[i+3] == '\n' && label[i+3] != '\x00') number_lines++;
    }
}
