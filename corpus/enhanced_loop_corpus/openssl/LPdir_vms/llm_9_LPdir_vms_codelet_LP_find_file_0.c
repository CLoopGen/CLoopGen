#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern char *r;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev = '\0';
    for (; *p; p++) {
        if (*p == '^' && p[1] != '\x00') {
            p++;
        } else if ((*p == ':' || *p == '>') && prev == *p) {
            l -= p + 1 - r;
            r = p + 1;
        } else if (*p == ']' && (p - r) > 10) {
            l -= p + 1 - r;
            r = p + 1;
        } else if (*p == ';') {
            l = p - r;
            break;
        }
        prev = *p;
    }
}
