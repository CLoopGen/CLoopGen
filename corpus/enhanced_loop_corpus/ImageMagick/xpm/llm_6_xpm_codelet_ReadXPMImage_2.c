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
    char *local_q = q;
    const char *local_p = p;
    MagickBooleanType local_active = active;
    for (; *local_p != '\x00'; ++local_p) {
        if (*local_p == '"') {
            if (local_active != MagickFalse)
                *local_q++ = '\n';
            local_active = local_active != MagickFalse ? MagickFalse : MagickTrue;
        }
        if (local_active != MagickFalse && *(local_p + 1) != '\x00')
            *local_q++ = *(local_p + 1);
    }
    q = local_q;
    p = local_p;
    active = local_active;
}
