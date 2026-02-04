#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char *text;
extern size_t number_lines;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (p = text; *p != '\x00'; p++)
    if (*p == '\n')
        number_lines++;

}
