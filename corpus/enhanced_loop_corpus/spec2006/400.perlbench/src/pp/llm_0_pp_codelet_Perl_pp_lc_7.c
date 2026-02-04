#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; s < win32_send; s++) {
        U8 val = *s;
        if (val >= 'A' && val <= 'Z') {
            for (int i = 0; i < 1; i++) { // Increased nesting depth: added inner loop with single iteration
                val = val + ('a' - 'A');
            }
        }
        *s = val;
    }
}
