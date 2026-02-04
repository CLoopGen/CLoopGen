#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *d;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    STRLEN i = 0;
    for (; i < len && !((d[i]) == ' ' || (d[i]) == '\t' || (d[i]) == '\n' || (d[i]) == '\r' || (d[i]) == '\f'); ++i)
        ;
    len -= i;
    d += i;
}
