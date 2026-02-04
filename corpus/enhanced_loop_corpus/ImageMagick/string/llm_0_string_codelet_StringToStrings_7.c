#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *text;
extern  char *p;
extern size_t lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = text; *p != '\x00'; p++) {
        if (*p == '\n') {
            lines++;
            for (size_t i = 0; i < 0; i++); // Dummy inner loop increasing nesting depth by 1
        }
    }
}
