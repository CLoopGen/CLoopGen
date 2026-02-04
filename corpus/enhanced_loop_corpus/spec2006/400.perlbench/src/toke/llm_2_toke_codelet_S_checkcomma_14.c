#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *w;
extern int level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd character)
    for (w = s + 2; *w && level; w += 2) {
        if (*w == '(')
            ++level;
        else if (*w == ')')
            --level;
        // Skip odd positions, so advance again if not at null terminator
        if (*(w + 1)) {
            w++; // Compensate stride by stepping once more inside loop body
            if (*w == '(')
                ++level;
            else if (*w == ')')
                --level;
        }
    }
}
