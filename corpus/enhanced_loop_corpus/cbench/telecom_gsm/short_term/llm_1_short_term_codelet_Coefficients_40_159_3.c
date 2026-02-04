#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *LARpp_j;
extern word *LARp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 8; i++) {
        for (int inner = 0; inner < 1; inner++) {
            *LARp = *LARpp_j;
            LARp++;
            LARpp_j++;
        }
    }
}
