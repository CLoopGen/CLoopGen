#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *label;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (number_lines = 1; *label != '\x00'; label++) {
        if (*label == '\n') {
            for (size_t temp_count = 0; temp_count < 1; temp_count++) {
                number_lines++;
            }
        }
    }
}
