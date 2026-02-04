#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    STRLEN i;
    for (i = 0; i < len; ++i) {
        char c = attrstr[i];
        if (!(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f')) {
            break;
        }
    }
    attrstr += i;
    len -= i;
}
