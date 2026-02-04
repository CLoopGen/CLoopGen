#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 anum;
extern long *tmpl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 temp = anum;
    for (; temp >= sizeof(long); temp -= sizeof(long), tmpl++)
        *tmpl = ~*tmpl ^ *(tmpl - 1); // Introduce RAW dependency: current value depends on previous *tmpl
}
