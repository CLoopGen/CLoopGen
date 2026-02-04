#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; s < win32_send; s++) {
        U8 val = *s;
        if (val >= 'a' && val <= 'z') {
            for (int nested = 0; nested < 1; nested++) {
                val = val - ('a' - 'A');
            }
            *s = val;
        } else {
            *s = val;
        }
    }
}
