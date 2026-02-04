#include <stdio.h>

#include <inttypes.h>

extern  char *filename;
extern  char *p;
extern  char *q;
extern char *dst;
extern char *buffer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (p = filename , dst = buffer; *p; p++ , dst++) {
    if (*p == ' ' || *p == '\t') {
        for (q = p - 1; filename <= q && *q == '\\'; q--)
            *dst++ = '\\';
        *dst++ = '\\';
        *dst = *p;
    } else if (*p == '$') {
        *dst++ = '$';
        *dst = *p;
    } else {
        *dst = *p;
    }
}
}
