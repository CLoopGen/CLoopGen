#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *pCurOut;
extern char *pEnd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char val = '0';
    for (size_t i = 0; pCurOut + i < pEnd; ++i) {
        *(pCurOut + i) = val;
    }
}
