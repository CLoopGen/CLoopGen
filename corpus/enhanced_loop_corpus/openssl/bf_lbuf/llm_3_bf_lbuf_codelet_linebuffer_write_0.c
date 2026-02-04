#include <stdio.h>

#include <inttypes.h>

extern  char *in;
extern int inl;
extern  char *p;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2), then adjust to ensure '\n' is caught
    char *end = in + inl;
    p = in;
    c = '\x00';

    // First pass: strided access (every 2nd byte)
    for (; p < end; p += 2) {
        c = *p;
        if (c == '\n') break;
    }

    // If we overshot or need to check odd positions, step back and scan forward one at a time
    if (c != '\n' && (p == end || p > in)) {
        p = (p == in) ? in : p - 1;  // rewind to last valid odd index if needed
        for (; p < end; p++) {
            c = *p;
            if (c == '\n') break;
        }
    }
}
