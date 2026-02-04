#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char **textlist;
extern size_t number_lines;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)number_lines; i++) {
        char *q;
        textlist[i] = p;
        for (q = p; (*q != '\x00') && (*q != '\r') && (*q != '\n'); q++);
        if (*q == '\r') {
            *q = '\x00';
            q++;
        } else if (*q == '\n') {
            *q = '\x00';
            q++;
        } else {
            *q = '\x00';
            q++;
        }
        p = q;
    }
}
