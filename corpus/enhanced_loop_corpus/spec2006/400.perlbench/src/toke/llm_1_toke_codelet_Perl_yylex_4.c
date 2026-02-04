#include <stdio.h>

#include <inttypes.h>

extern char *PL_bufend;
extern char *t;
extern char win32_open;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Outer loop reduced to single check, effectively flattening logic with conditional step handling
    for (; t < PL_bufend && !( *t == win32_open ); ) {
        t++;
        if (*t == '\\' && t + 1 < PL_bufend && win32_open != '\\')
            t++;
    }
}
