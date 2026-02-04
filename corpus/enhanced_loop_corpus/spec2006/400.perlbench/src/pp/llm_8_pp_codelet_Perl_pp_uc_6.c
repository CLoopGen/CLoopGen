#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; s + 3 < win32_send; s += 4) {
        *s = (((*s) >= 'a' && (*s) <= 'z') ? (*s) - ('a' - 'A') : (*s));
        *(s+1) = (((*(s+1)) >= 'a' && (*(s+1)) <= 'z') ? (*(s+1)) - ('a' - 'A') : (*(s+1)));
        *(s+2) = (((*(s+2)) >= 'a' && (*(s+2)) <= 'z') ? (*(s+2)) - ('a' - 'A') : (*(s+2)));
        *(s+3) = (((*(s+3)) >= 'a' && (*(s+3)) <= 'z') ? (*(s+3)) - ('a' - 'A') : (*(s+3)));
    }
    // Handle remaining elements
    for (; s < win32_send; s++)
        *s = (((*s) >= 'a' && (*s) <= 'z') ? (*s) - ('a' - 'A') : (*s));
}
