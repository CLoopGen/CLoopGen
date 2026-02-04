#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-element access with boundary check
    for (U8 *ptr = s; ptr + 1 < win32_send; ptr += 2) {
        ptr[0] = ((ptr[0] >= 'a' && ptr[0] <= 'z') ? ptr[0] - ('a' - 'A') : ptr[0]);
        ptr[1] = ((ptr[1] >= 'a' && ptr[1] <= 'z') ? ptr[1] - ('a' - 'A') : ptr[1]);
    }
    // Handle remaining element if length is odd
    if (s <= win32_send - 1) {
        U8 *ptr = win32_send - 1;
        *ptr = ((*ptr >= 'a' && *ptr <= 'z') ? *ptr - ('a' - 'A') : *ptr);
    }
}
