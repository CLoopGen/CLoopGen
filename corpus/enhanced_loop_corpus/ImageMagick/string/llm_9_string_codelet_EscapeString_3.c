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
    char prev = '\x01';
    for (p = source; *p != '\x00'; p++, prev = *(p - (prev == '\x01' ? 0 : 1))) {
        if ((*p == '\\') || (*p == escape)) {
            *q++ = '\\';
            *q++ = *p;
        } else {
            *q++ = *p;
        }
    }
}
