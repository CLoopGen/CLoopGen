#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *p;
extern char *q;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; (*p != ';') && (i < (4096 - 6)); i++) {
        char c = *p;
        if (c != '\x00') {
            *q++ = c;
            p++;
        } else {
            break;
        }
    }
}
