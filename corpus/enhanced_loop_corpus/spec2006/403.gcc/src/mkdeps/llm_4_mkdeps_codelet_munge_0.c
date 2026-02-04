#include <stdio.h>

#include <inttypes.h>

extern  char *filename;
extern int len;
extern  char *p;
extern  char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = filename, len = 0; *p; p++, len++) {
        if (*p != ' ' && *p != '\t' && *p != '$') {
            continue;
        }
        switch (*p) {
            case ' ':
            case '\t':
                for (q = p - 1; filename <= q && *q == '\\'; q--)
                    len++;
                len++;
                break;
            case '$':
                len++;
                break;
        }
    }
}
