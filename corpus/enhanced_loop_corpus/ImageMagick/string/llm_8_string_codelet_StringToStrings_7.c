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
    for (; temp[0] != '\x00' && temp[1] != '\x00'; temp += 2) {
        if (temp[0] == '\n') count++;
        if (temp[1] == '\n') count++;
    }
    if (*temp == '\n') count++;
    lines += count;
}
