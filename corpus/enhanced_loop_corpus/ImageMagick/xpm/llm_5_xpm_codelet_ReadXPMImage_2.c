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
        char current = *p;
        if (current == '"' && ++p) {
            *q++ = '\n';
            active = MagickFalse;
        } else {
            p++;
            if (!active) continue;
            *q++ = current;
        }
    }
}
