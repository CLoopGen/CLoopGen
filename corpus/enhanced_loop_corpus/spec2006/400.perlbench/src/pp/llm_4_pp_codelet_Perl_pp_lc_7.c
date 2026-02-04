#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; s < win32_send; s++) {
        if (!((*s) >= 'A' && (*s) <= 'Z')) continue;
        *s = (*s) + ('a' - 'A');
    }
}
