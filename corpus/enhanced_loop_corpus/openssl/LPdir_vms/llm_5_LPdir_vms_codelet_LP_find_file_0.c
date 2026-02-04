#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern char *r;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char c;
    for (; (c = *p); p++) {
        if (c == '^' && p[1] != '\x00') {
            p++;
        } else if (c == ';' || c == ':' || c == '>' || c == ']') {
            if (c == ';') {
                l = p - r;
                break;
            } else {
                l -= p + 1 - r;
                r = p + 1;
            }
        }
    }
}
