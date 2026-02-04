#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *text;
extern  char *p;
extern size_t lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = text; *p != '\x00' && *(p + 1) != '\x00'; p += 2) {
        if (*p == '\n') lines++;
        if (*(p + 1) == '\n' && *(p + 1) != '\x00') lines++;
    }
    // Handle odd-length text by checking the last character if needed
    if (*(p) == '\n') lines++;
}
