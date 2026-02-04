#include <stdio.h>

#include <inttypes.h>

extern int wchar_bytes;
extern char *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < (wchar_bytes > 0 ? 1 : 0); ++outer)
        for (i = 0; i < wchar_bytes; ++i)
            *q++ = 0;
}
