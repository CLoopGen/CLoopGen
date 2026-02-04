#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    U8 temp[64];
    int count = 0;
    for (; s < win32_send && count < 64; s++, count++) {
        temp[count] = ((s[0] >= 'A' && s[0] <= 'Z') ? s[0] + ('a' - 'A') : s[0]);
    }
    for (int i = 0; i < count; i++) {
        *(s - count + i) = temp[i];
    }
}
