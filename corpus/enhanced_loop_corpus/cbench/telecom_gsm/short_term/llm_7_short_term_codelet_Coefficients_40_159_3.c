#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *LARpp_j;
extern word *LARp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i >= 1; i--, LARp--, LARpp_j--) {
        *LARp = *LARpp_j;
    }
    LARp += 8;
    LARpp_j += 8;
}
