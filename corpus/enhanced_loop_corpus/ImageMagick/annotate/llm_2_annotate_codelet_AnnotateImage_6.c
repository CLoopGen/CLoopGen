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
    ssize_t j;
    char *q;
    for (j = 0; j < (ssize_t)number_lines; j++) {
        textlist[j] = p;
        q = p;
        while (*q != '\x00' && *q != '\r' && *q != '\n') {
            q++;
        }
        *q = '\x00';
        if (*(q + 1) == '\n') {
            q++;
        }
        p = q + 1;
    }
}
