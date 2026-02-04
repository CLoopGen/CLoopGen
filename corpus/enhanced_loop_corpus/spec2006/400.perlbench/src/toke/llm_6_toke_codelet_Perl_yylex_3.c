#include <stdio.h>

#include <inttypes.h>

extern char *PL_bufend;
extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev_t = '\0';
    for (t++; t < PL_bufend && *t != *s; ) {
        if (*t == '\\' && prev_t == '\\') {
            t++;
        }
        prev_t = *t++;
    }
}
