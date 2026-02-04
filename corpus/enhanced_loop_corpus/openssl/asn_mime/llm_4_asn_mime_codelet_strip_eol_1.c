#include <stdio.h>

#include <inttypes.h>

extern char *linebuf;
extern int flags;
extern int len;
extern char *p;
extern char c;
extern int is_eol;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = linebuf + len - 1; len > 0; len--, p--) {
        c = *p;
        if (c == '\n') {
            is_eol = 1;
            continue;
        }
        if (!is_eol || (flags & 524288) == 0 || c != 32) {
            if (c != '\r') {
                break;
            }
        }
    }
}
