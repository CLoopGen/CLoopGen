#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *d;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; len > 0 && ((*d) == ' ' || (*d) == '\t' || (*d) == '\n' || (*d) == '\r' || (*d) == '\f'); len -= 2, d += (len > 1) ? 2 : 1)
        if (len == 1) break;
}
