#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bufend;
extern char *t;
extern char win32_open;
extern char close;
extern I32 brackets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 stride = 2;
    char *p = t + 1;
    for (; p < PL_bufend; p += stride) {
        if (*p == '\\' && p + 1 < PL_bufend)
            p++;
        else if (*p == close && --brackets <= 0)
            break;
        else if (*p == win32_open)
            brackets++;
    }
    t = p >= PL_bufend ? PL_bufend : p - stride + 1;
}
