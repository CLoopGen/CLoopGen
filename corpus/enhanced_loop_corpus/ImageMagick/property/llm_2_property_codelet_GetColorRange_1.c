#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element)
    ptrdiff_t stride = 2;
    char *end = start_color + 4096;
    for (p = start_color; p < end && (*p != '-') && (*p != '\x00'); p += stride) {
        if (*p == '(') {
            p++; // Move past '('
            while (p < end && *p != ')' && *p != '\x00') {
                p++;
            }
            if (p >= end || *p == '\x00') {
                break;
            }
        }
    }
    // Rewind p to last valid position if it overshot due to stride
    if (p > start_color + 4095) {
        p = start_color + 4095;
    }
}
