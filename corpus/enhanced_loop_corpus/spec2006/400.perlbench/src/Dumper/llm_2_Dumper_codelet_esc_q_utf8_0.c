#include <stdio.h>

#include <inttypes.h>

extern char *src;
extern char *s;
extern char *win32_send;
extern char *r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (process every second character)
    // This changes the access pattern from consecutive to strided
    for (s = src; s < win32_send; s += 2) {
        char k = *s;
        if (k == '\'' || k == '\\')
            *r++ = '\\';
        *r++ = k;
    }
}
