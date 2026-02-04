#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (skip every other character)
    char *p;
    for (p = s + 1; p != NULL; p += 2) {
        if ((*p) != ' ' && (*p) != '\t' && *p != '\r') {
            t = p;
            break;
        }
        // Check next odd index if current is boundary
        if (*(p + 1) != ' ' && *(p + 1) != '\t' && *(p + 1) != '\r') {
            t = p + 1;
            break;
        }
    }
}
