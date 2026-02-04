#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char **pp = &p;
    *pp = start_color;
    for (; (**pp != '-') && (**pp != '\x00'); (*pp)++) {
        if (**pp == '(') {
            (*pp)++;
            for (; (**pp != ')') && (**pp != '\x00'); (*pp)++)
                ;
            if (**pp == '\x00')
                break;
        }
    }
}
