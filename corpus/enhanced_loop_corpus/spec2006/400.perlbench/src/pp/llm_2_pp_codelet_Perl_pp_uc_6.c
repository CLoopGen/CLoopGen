#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2)
    for (U8 *ptr = s; ptr < win32_send; ptr += 2)
        *ptr = ((*ptr >= 'a' && *ptr <= 'z') ? *ptr - ('a' - 'A') : *ptr);
}
