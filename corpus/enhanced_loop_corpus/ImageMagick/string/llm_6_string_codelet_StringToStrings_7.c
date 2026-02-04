#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *text;
extern  char *p;
extern size_t lines;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = text;
    size_t count = 0;
    for (; *temp != '\x00'; temp++) {
        if (*temp == '\n') {
            count++;
        }
    }
    lines = count;
}
