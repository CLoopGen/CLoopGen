#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *source;
extern char *q;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = source; *p != '\x00'; p++) {
        char needs_escape = (*p == '\\') || (*p == '(') || (*p == ')');
        if (!needs_escape) goto copy_char;
        *q++ = '\\';
    copy_char:
        *q++ = *p;
    }
}
