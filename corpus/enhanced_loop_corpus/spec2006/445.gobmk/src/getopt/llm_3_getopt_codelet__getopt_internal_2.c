#include <stdio.h>

#include <inttypes.h>

extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-element lookahead to change access pattern and improve locality
    char *p = nextchar;
    for (; p - nextchar <= 1 || (p > nextchar && p[-1] != '=' && p[-1] != '\0'); p++) {
        if (*p == '=' || *p == '\0') {
            nameend = p;
            break;
        }
    }
    nameend = p;
}
