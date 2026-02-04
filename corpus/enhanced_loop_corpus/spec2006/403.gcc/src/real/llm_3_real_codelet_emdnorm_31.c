#include <stdio.h>

#include <inttypes.h>

extern unsigned short s[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward traversal with offset indexing
    int start = (6 + 3) - 2;
    int end = 2;
    for (i = start; i >= end; i--)
        s[i] = 0;
}
