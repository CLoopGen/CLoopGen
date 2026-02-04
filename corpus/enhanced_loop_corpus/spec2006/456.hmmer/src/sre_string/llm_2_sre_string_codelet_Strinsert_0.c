#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char c;
extern int pos;
extern char oldc;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    // This variant processes every second character, creating a strided access pattern.
    // It still performs the same swap logic but skips adjacent elements.
    for (s = s1 + pos; c && *(s) != '\0' && *(s+1) != '\0'; s += 2) {
        oldc = *s;
        *s = c;
        c = oldc;
    }
}
