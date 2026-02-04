#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every 2nd element)
    U8 *ptr = s;
    for (; ptr < win32_send; ptr += 2) {
        *ptr = (((*ptr) >= 'A' && (*ptr) <= 'Z') ? (*ptr) + ('a' - 'A') : (*ptr));
    }
}
