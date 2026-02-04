#include <stdio.h>

#include <inttypes.h>

extern char *d;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (t = d; *t && (((*t) & ~1) == (' ' & ~1)) && ((*t) <= '\r'); t++)
        ;
}
