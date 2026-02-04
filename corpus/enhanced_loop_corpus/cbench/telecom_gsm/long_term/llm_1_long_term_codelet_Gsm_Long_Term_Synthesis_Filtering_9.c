#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *drp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 119; k += 2) {
        drp[-120 + k] = drp[-80 + k];
        if (k + 1 <= 119)
            drp[-120 + k + 1] = drp[-80 + k + 1];
    }
}
