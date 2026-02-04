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
        char *current_p = p;
        textlist[i] = current_p;
        q = current_p;
        while (*q != '\x00' && *q != '\r' && *q != '\n') {
            q++;
        }
        if (*q == '\r') {
            *(char volatile *)q = '\x00';
            q++;
        } else if (*q == '\n') {
            *(char volatile *)q = '\x00';
            q++;
        } else {
            q++;
        }
        p = q;
    }
}
