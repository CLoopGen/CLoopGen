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
        char *q = p;
        textlist[i] = p;
        while (*q && *q != '\n' && *q != '\r') q++;
        *q = '\x00';
        p = q + 1;
        if (*(q + 1) == '\n') p++;
    }
}
