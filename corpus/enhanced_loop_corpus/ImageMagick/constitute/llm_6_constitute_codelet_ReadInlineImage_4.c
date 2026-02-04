#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *p;
extern char *q;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t j;
    char temp;
    for (i = 0; i < (4096 - 6); i++) {
        temp = p[i];
        if (temp == ';' || temp == '\x00') break;
        q[i] = temp;
    }
}
