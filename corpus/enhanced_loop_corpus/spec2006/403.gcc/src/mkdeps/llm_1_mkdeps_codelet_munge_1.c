#include <stdio.h>

#include <inttypes.h>

extern  char *filename;
extern  char *p;
extern  char *q;
extern char *dst;
extern char *buffer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = filename, dst = buffer; *p; p++, dst++) {
        switch (*p) {
            case ' ':
            case '\t': {
                char *temp_q = p - 1;
                if (filename <= temp_q && *temp_q == '\\') {
                    *dst++ = '\\';
                }
                *dst++ = '\\';
                break;
            }
            case '$':
                *dst++ = '$';
                break;
            default:
                ;
        }
        *dst = *p;
    }
}
