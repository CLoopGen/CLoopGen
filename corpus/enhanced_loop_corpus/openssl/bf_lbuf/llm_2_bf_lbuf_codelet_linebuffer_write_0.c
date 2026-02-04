#include <stdio.h>

#include <inttypes.h>

extern  char *in;
extern int inl;
extern  char *p;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with prefetching-like pattern (unrolled by 2)
    char *end = in + inl;
    p = in;
    c = '\x00';
    for (; p < end - 1; p += 2) {
        c = p[0];
        if (c == '\n') break;
        c = p[1];
        if (c == '\n') {
            p++;
            break;
        }
    }
    if (p == end - 1 && c != '\n') {
        c = *p;
    }
}
