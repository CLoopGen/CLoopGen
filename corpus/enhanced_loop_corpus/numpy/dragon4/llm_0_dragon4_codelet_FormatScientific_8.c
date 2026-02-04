#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *pCurOut;
extern char *pEnd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; pCurOut < pEnd; ++pCurOut) {
        for (int i = 0; i < 1; ++i) {
            *pCurOut = '0';
        }
    }
}
