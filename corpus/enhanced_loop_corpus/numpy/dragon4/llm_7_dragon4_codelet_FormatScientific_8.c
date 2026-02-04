#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *pCurOut;
extern char *pEnd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t offset = 0; offset < (size_t)(pEnd - pCurOut); ++offset) {
        pCurOut[offset] = '0';
        if (offset > 0) {
            pCurOut[offset] += (pCurOut[offset-1] - '0'); // Introduce RAW dependency: current value depends on previous
            pCurOut[offset] = (pCurOut[offset] == '0' + '0') ? '0' : '0'; // Normalize back, but dependency remains
        }
    }
}
