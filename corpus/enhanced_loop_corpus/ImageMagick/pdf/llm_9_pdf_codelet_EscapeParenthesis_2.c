#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *source;
extern char *q;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char c;
    for (p = source; (c = *p); p += 2) {
        if ((c == '\\') || (c == '(') || (c == ')'))
            *q++ = '\\';
        *q++ = c;

        if (*(p+1) == '\x00') break;
        
        c = *(p+1);
        if ((c == '\\') || (c == '(') || (c == ')'))
            *q++ = '\\';
        *q++ = c;
    }
}
