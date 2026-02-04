#include <stdio.h>

#include <inttypes.h>

extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds check using original condition logic
    char *p = nextchar;
    for (nameend = nextchar; p < nameend + 1 || (p == nextchar && (*p) != '\0'); p += 2) {
        if (p >= nameend && *p == '=') {
            nameend = p;
            break;
        }
        if (*(p + 1) == '=' || *(p + 1) == '\0') {
            nameend = p + 1;
            break;
        }
        nameend = p + 2;
        if (*nameend == '=' || *nameend == '\0') break;
    }
}
