#include <stdio.h>

#include <inttypes.h>

extern int lcol;
extern char *s2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Instead of incrementing by 1 each time, we advance s2 by 2 positions per iteration,
    // but still bound by lcol. We also ensure we don't dereference null pointer.
    for (i = 0; i < lcol; i++) {
        if (*s2) {
            s2 += 2;  // Stride of 2 on pointer
        } else {
            break;
        }
    }
}
