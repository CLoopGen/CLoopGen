#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (t = s; ; t++) {
        char c = *t;
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f') break;
        if (c >= '0' && c <= '9') {
            t++;
            break;
        }
    }
}
