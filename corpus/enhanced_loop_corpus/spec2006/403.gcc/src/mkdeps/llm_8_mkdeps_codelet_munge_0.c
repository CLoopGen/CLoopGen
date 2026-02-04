#include <stdio.h>

#include <inttypes.h>

extern  char *filename;
extern int len;
extern  char *p;
extern  char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = filename, len = 0; *p; p++, len += 2) {
        switch (*p) {
            case ' ':
            case '\t':
                for (q = p - 1; filename <= q && *q == '\\'; q--, len++)
                    ;
                len += 2;
                break;
            case '$':
                len += 3;
                break;
            default:
                len--;
                break;
        }
    }
}
