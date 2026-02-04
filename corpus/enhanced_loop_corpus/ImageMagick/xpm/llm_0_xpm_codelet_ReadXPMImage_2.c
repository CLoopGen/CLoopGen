#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

extern char *p;
extern char *q;
extern char *xpm_buffer;
extern MagickBooleanType active;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (q = xpm_buffer; *p != '\x00';) {
    for (; *p != '\x00' && *p++ == '"';) {
        if (active != MagickFalse)
            *q++ = '\n';
        active = active != MagickFalse ? MagickFalse : MagickTrue;
        break;
    }
    if (*p != '\x00' && active != MagickFalse)
        *q++ = (*p++);
}
}
