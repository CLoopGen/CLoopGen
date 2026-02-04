#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal from win32_send-1 down to s
    U8 *end = win32_send - 1;
    for (; end >= s; end--) {
        *end = (((*end) >= 'A' && (*end) <= 'Z') ? (*end) + ('a' - 'A') : (*end));
    }
}
