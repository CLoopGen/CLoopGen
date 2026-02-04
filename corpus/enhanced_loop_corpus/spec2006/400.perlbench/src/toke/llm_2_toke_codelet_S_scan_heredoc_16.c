#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *peek;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second character)
    for (peek = s; ((*peek) == ' ' || (*peek) == '\t'); peek += 2) {
        // Check current char, then skip one unconditionally
        if (*(peek + 1) != ' ' && *(peek + 1) != '\t') {
            break;
        }
    }
}
