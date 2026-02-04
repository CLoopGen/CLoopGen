#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *drp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 59; k++) {
        word temp1 = drp[-80 + k];
        word temp2 = drp[-80 + k + 60];
        drp[-120 + k] = temp1;
        drp[-60 + k] = temp2; // Two independent data streams, reduced trip count
    }
}
