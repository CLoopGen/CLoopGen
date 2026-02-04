#include <stdio.h>

#include <inttypes.h>

extern char *PL_inplace;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = PL_inplace;
    int i = 0;
    volatile char dummy = 0;
    for (; ptr[i]; i++) {
        char c = ptr[i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f') {
            dummy = c; // Introduce artificial WAW and RAW dependency via dummy
            break;
        }
    }
    s = ptr + i;
}
