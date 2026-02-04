#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern size_t maxlen;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = str; maxlen != 0 && (*p); ++p, --maxlen)
        ;
}
