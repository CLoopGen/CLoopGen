#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *LARpp_j;
extern word *LARp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word temp;
    for (i = 1; i <= 8; i++) {
        temp = *(LARpp_j + i);
        *(LARp + i) = temp;
    }
}
