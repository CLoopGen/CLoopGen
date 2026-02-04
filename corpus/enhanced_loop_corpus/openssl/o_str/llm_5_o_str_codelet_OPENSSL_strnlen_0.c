#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern size_t maxlen;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char c;
    for (p = str; (c = *p) != '\x00' && maxlen > 0; ++p, --maxlen)
        if (!c) break;
}
