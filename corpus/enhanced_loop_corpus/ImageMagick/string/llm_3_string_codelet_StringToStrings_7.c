#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *text;
extern  char *p;
extern size_t lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; *(text + i) != '\x00'; i += 2){
        if (*(text + i) == '\n')
            lines++;
        if (*(text + i + 1) != '\x00' && *(text + i + 1) == '\n')
            lines++;
    }
    // Handle odd-length string ending
    if (*(text + i - 1) != '\x00' && *(text + i) == '\n')
        lines++;
}
