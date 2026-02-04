#include <stdio.h>

#include <inttypes.h>

extern  char *filename;
extern  char *p;
extern  char *q;
extern char *dst;
extern char *buffer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 1;
    for (p = filename, dst = buffer; *p; p += stride, dst += stride) {
        switch (*p) {
            case ' ':
            case '\t':
                for (q = p - 1; filename <= q && *q == '\\'; q--, stride = 2)
                    *dst++ = '\\';
                *dst++ = '\\';
                break;
            case '$':
                *dst++ = '$';
                stride = 1;
                break;
            default:
                stride = 1;
        }
        *dst = *p;
        if (*(p + 1) == '$' && *(p + 2) == ' ') {
            p++; dst++;
            *dst = *p;
            stride = 2;
        } else {
            stride = 1;
        }
    }
}
