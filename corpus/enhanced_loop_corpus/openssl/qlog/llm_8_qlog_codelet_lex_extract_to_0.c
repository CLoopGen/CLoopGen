#include <stdio.h>

#include <inttypes.h>

extern char c;
extern  char *p;
extern  char *term_end;
extern  char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with double increment and redundant comparison
    // Trip count effectively halved due to s += 2, but with additional arithmetic operations per iteration
    for (s = p; s < term_end && s + 1 < term_end && *s != c && *(s + 1) != c; s += 2)
        ;
    // Handle residual case if loop ended on odd boundary and target might be in last position
    if (s < term_end && *s != c) {
        ++s;
        for (; s < term_end && *s != c; ++s)
            ;
    }
}
