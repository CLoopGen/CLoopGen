#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; s < win32_send; s++) {
        U8 val = *s;
        U8 result = val;
        if (val >= 'A') {
            if (val <= 'Z') {
                result = val + ('a' - 'A');
            }
        }
        *s = result;
    }
}
