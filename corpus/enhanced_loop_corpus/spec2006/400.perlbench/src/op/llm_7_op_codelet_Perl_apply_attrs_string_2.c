#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    STRLEN i;
    char volatile *ptr = attrstr;
    for (i = 0; i < len && !(ptr[i] == ' ' || ptr[i] == '\t' || ptr[i] == '\n' || ptr[i] == '\r' || ptr[i] == '\f'); ++i)
        ;
    attrstr += i;
    len -= i;
}
