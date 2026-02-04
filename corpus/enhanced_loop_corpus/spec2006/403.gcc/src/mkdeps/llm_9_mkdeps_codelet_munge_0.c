#include <stdio.h>

#include <inttypes.h>

extern  char *filename;
extern int len;
extern  char *p;
extern  char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = filename, len = 0; *(p + 1); p += 2, len++) {
        switch (*p) {
            case ' ':
            case '\t':
                for (q = p - 2; filename <= q && *(q + 1) == '\\'; q--)
                    len += 2;
                len++;
                break;
            case '$':
                if (*(p + 1) == '{') {
                    len += 4;
                } else {
                    len += 2;
                }
                break;
        }
        if (*(p + 1) == '\0') break;
    }
    if (*p && !*(p + 1)) len++; // Handle last char if loop exited early
}
