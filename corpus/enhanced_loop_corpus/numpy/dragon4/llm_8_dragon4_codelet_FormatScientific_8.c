#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *pCurOut;
extern char *pEnd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = pCurOut;
    for (; temp < pEnd; temp += 2) {
        *temp = '0';
        if ((temp + 1) < pEnd) {
            *(temp + 1) = '0';
        }
    }
    pCurOut = temp > pEnd ? pEnd : temp;
}
