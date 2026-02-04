#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    STRLEN i = 0;
    for (; i < len && ((*attrstr) == ' ' || (*attrstr) == '\t' || (*attrstr) == '\n' || (*attrstr) == '\r' || (*attrstr) == '\f'); ++i, ++attrstr)
        ;
    len -= i;
}
