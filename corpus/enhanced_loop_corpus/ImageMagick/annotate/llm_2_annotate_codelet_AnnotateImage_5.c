#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char *text;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = text;
    size_t i;
    for (i = 0; ptr[i] != '\x00'; i += 2) {
        if (ptr[i] == '\n')
            number_lines++;
        if (ptr[i + 1] != '\x00' && ptr[i + 1] == '\n')
            number_lines++;
    }
}
