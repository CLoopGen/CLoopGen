#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int *len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    const char *ps = s + i;
    const char *psep = sep;
    int b;
    for (; *ps; ps++, (*len)++) {
        b = 0;
        const char *js = psep;
        for (; *js; js++)
            if (*ps == *js) {
                b = 1;
                break;
            }
        if (b)
            break;
    }
    i = ps - s; // update global i to reflect current position
}
