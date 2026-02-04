#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char tmpbuf[4096];
extern char *s;
extern I32 len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (forward and backward fill)
    // We traverse the input string with normal increment, but write into tmpbuf in a strided pattern.
    // Even indices filled forward, odd indices filled backward to create non-consecutive writes.
    len = 0;
    char *ptr = s;
    I32 even_idx = 0;
    I32 odd_idx = sizeof tmpbuf - 1;

    for (; *ptr && *ptr != ';'; len++, ptr++) {
        if (even_idx < sizeof tmpbuf && len % 2 == 0) {
            tmpbuf[even_idx] = *ptr;
            even_idx += 2;
        } else if (odd_idx >= 0 && len % 2 == 1) {
            tmpbuf[odd_idx] = *ptr;
            odd_idx -= 2;
        }
    }
    s = ptr; // Update original s
}
