#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; len; --len, ++attrstr) {
        char c = *attrstr;
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f') {
            continue;
        } else {
            break;
        }
    }
}
