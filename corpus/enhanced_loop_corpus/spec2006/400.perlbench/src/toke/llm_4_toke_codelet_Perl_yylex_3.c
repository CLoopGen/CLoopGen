#include <stdio.h>

#include <inttypes.h>

extern char *PL_bufend;
extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (t++; t < PL_bufend && *t != *s; t++) {
        if (*t == '\\' && (*(t+1) == '\\' || *(t+1) == *s)) {
            t++;
            continue;
        }
    }
}
