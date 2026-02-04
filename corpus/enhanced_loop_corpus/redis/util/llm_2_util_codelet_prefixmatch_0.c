#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *pattern;
extern int patternLen;
extern int backslashCount;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element backwards, then handle remainder)
    int i = patternLen - 2;
    // First pass: process indices with stride of 2 (even offsets from end)
    for (; i >= 0; i -= 2) {
        if (pattern[i] == '\\')
            ++backslashCount;
        else
            break;
    }
    // Second pass: if the sequence didn't break early and we need to check the adjacent odd index
    if (i < 0 && (patternLen - 2) % 2 != 0) {
        i = patternLen - 3;  // Continue with next lower index if exists
        for (; i >= 0; i -= 2) {
            if (pattern[i] == '\\')
                ++backslashCount;
            else
                break;
        }
    }
}
