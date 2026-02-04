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
    char prev = '\x00';
    for (p = source; *p != '\x00'; p++) {
        if ((*p == '\\') || (*p == escape) || (prev == escape && *p == *p)) 
            *q++ = '\\';
        *q++ = (*p);
        prev = *p;
    }
}
