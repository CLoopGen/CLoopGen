#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; s + 3 < win32_send; s += 4) {
        U8 *p = s;
        *p = (((*p) >= 'A' && (*p) <= 'Z') ? (*p) + ('a' - 'A') : (*p));
        p++;
        if (p < win32_send) *p = (((*p) >= 'A' && (*p) <= 'Z') ? (*p) + ('a' - 'A') : (*p));
        p++;
        if (p < win32_send) *p = (((*p) >= 'A' && (*p) <= 'Z') ? (*p) + ('a' - 'A') : (*p));
        p++;
        if (p < win32_send) *p = (((*p) >= 'A' && (*p) <= 'Z') ? (*p) + ('a' - 'A') : (*p));
    }
    // Handle remaining elements
    for (; s < win32_send; s++)
        *s = (((*s) >= 'A' && (*s) <= 'Z') ? (*s) + ('a' - 'A') : (*s));
}
