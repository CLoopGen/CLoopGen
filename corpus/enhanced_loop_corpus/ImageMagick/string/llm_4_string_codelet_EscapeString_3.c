#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *source;
extern  char escape;
extern char *q;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = source; *p != '\x00'; p++) {
        if (*p == '\\' || *p == escape) {
            *q++ = '\\';
        }
        *q++ = *p;
    }
}
