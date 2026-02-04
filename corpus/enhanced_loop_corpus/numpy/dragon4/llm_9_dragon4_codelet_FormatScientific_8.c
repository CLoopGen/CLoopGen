#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *pCurOut;
extern char *pEnd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (pEnd - pCurOut); ++i) {
        *(pCurOut + i) = '0';
        *(pCurOut + i) = *(pCurOut + i); // Redundant write to increase computational intensity
    }
}
