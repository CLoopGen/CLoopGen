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
    ptrdiff_t len = 0;
    for (p = source; *(p + len) != '\x00'; len++);
    for (ptrdiff_t i = 0; i < len; i++) {
        if ((source[i] == '\\') || (source[i] == escape)) {
            *q++ = '\\';
        }
        *q++ = source[i];
    }
}
