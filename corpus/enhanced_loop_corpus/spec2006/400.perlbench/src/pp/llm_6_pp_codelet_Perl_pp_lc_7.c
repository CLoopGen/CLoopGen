#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    U8 *ptr = s;
    for (; ptr < win32_send; ptr++) {
        U8 val = *ptr;
        val = (val >= 'A' && val <= 'Z') ? val + ('a' - 'A') : val;
        *ptr = val;
    }
}
