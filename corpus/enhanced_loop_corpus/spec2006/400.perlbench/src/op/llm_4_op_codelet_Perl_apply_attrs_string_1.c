#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; len; --len, ++attrstr) {
        if ((*attrstr) != ' ' && (*attrstr) != '\t' && (*attrstr) != '\n' && (*attrstr) != '\r' && (*attrstr) != '\f') {
            break;
        }
    }
}
