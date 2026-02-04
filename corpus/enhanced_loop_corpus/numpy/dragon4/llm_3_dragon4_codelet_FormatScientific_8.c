#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *pCurOut;
extern char *pEnd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    char *p = pCurOut;
    for (; p < pEnd; p += stride) {
        *p = '0';
        if (p + 1 < pEnd) {
            *(p + 1) = '0';
        }
    }
    for (; pCurOut < pEnd; ++pCurOut) {
        if (*pCurOut != '0') {
            *pCurOut = '0';
        }
    }
}
