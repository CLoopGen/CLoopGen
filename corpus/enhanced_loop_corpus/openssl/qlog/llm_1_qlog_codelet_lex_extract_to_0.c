#include <stdio.h>

#include <inttypes.h>

extern char c;
extern  char *p;
extern  char *term_end;
extern  char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (p < term_end && *p != c) {
        for (s = p + 1; s < term_end && *s != c; ++s) {
            // Single loop remains, but initial condition handled outside to conceptually reduce effective nesting complexity
        }
        s = p; // Ensure s starts at p in case no iterations occur
    } else {
        s = p;
    }
}
