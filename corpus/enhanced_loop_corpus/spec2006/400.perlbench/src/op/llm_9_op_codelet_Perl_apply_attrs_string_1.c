#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; len > 4 && ((*attrstr) == ' ' || (*attrstr) == '\t' || (*attrstr) == '\n' || (*attrstr) == '\r' || (*attrstr) == '\f'); --len, ++attrstr)
        ;
    if (len <= 4) {
        for (; ((*attrstr) == ' ' || (*attrstr) == '\t' || (*attrstr) == '\n' || (*attrstr) == '\r' || (*attrstr) == '\f') && len; --len, ++attrstr)
            ;
    }
}
