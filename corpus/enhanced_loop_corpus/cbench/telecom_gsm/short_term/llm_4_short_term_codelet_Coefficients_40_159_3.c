#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *LARpp_j;
extern word *LARp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 8; i++, LARp++, LARpp_j++) {
        if (i % 2 == 1) {
            *LARp = *LARpp_j;
        }
    }
}
