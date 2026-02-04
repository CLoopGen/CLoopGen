#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char c;
extern int pos;
extern char oldc;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled operations
    char *ptr = s1 + pos;
    for (s = ptr; c; s += 2) {
        // Unroll two iterations to increase arithmetic and memory operations
        oldc = *s;
        *s = c;
        c = oldc;

        if (*(s + 1)) {
            oldc = *(s + 1);
            *(s + 1) = c;
            c = oldc;
        } else {
            break;
        }
    }
}
