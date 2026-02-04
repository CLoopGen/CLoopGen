#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; len > 0 && ((*attrstr) >= 'a' && (*attrstr) <= 'z' || (*attrstr) >= 'A' && (*attrstr) <= 'Z' || (*attrstr) == '_') && len; --len, ++attrstr)
        ;
}
