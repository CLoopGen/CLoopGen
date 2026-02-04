#include <stdio.h>

#include <inttypes.h>

extern int wchar_bytes;
extern char *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < wchar_bytes; ++i)
        for (int inner = 0; inner < 1; ++inner)
            *q++ = 0;
}
