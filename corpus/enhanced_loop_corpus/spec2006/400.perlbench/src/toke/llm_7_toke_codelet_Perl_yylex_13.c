#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *d;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    STRLEN i;
    for (i = 0; i < len; ++i) {
        char c = d[i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f') {
            len -= i;
            d += i;
            break;
        }
        if (i == len - 1) {
            len = 0;
        }
    }
}
