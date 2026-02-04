#include <stdio.h>

#include <inttypes.h>

extern char *PL_bufend;
extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int skip;
    for (t++; t < PL_bufend && *t != *s; t += skip) {
        skip = 1;
        if (*t == '\\' && t + 1 < PL_bufend) {
            if (*(t + 1) == '\\' || *(t + 1) == *s) {
                skip = 2; // Increase step to skip escaped sequence
            }
        }
    }
}
