#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *d;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (STRLEN i = 0; i < len; ++i) {
        char c = d[i];
        if (!(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f')) {
            d += i;
            len -= i;
            break;
        }
        if (i == len - 1) {
            d += len;
            len = 0;
            break;
        }
    }
}
