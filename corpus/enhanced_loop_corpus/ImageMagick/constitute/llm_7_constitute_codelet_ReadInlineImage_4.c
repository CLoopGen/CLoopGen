#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *p;
extern char *q;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t index = 0;
    char prev = '\0';
    for (i = 0; (*p != ';') && (*p != '\x00') && (i < (4096 - 6)); i++) {
        char curr = *p;
        q[index] = curr;
        prev = curr;
        p++;
        index++;
    }
    i = index;
}
