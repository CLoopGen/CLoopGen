#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *drp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 239; k += 2) {
        drp[-120 + k] = drp[-80 + k];
        drp[-119 + k] = drp[-79 + k]; // Double the effective work per iteration
    }
}
