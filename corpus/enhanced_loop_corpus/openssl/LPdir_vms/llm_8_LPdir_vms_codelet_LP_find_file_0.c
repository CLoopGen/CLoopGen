#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern char *r;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t count = 0;
    for (; *p && count < 1024; p++, count++) {
        if (*p == '^' && p[1] != '\x00') {
            p++;
            l += 2;
        } else if (*p == ':' || *p == '>' || *p == ']') {
            size_t segment_length = p + 1 - r;
            l -= segment_length;
            r = p + 1;
            l += (segment_length & 1) ? 1 : 0;
        } else if (*p == ';') {
            l = p - r;
            break;
        }
    }
}
