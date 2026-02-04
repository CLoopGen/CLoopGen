#include <stdio.h>

#include <inttypes.h>

extern char bound[33];
extern char c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every 2nd element in two passes)
    int i;
    char c;
    // First pass: even indices
    for (i = 0; i < 32; i += 2) {
        c = bound[i] & 15;
        if (c < 10)
            c += '0';
        else
            c += 'A' - 10;
        bound[i] = c;
    }
    // Second pass: odd indices
    for (i = 1; i < 32; i += 2) {
        c = bound[i] & 15;
        if (c < 10)
            c += '0';
        else
            c += 'A' - 10;
        bound[i] = c;
    }
}
