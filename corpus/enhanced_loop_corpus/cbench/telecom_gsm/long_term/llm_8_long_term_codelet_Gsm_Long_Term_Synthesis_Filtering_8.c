#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *erp;
extern word *drp;
extern longword ltmp;
extern int k;
extern word brp;
extern word drpp;
extern word Nr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 19; k++) {
        drpp = (((((longword)(brp) * (longword)(drp[k - Nr]) + 8192)) >> (14)));
        ltmp = (longword)(erp[k]) + (longword)(drpp);
        if (ltmp > 32767) {
            drp[k] = 32767;
        } else if (ltmp < -32768) {
            drp[k] = -32768;
        } else {
            drp[k] = (word)ltmp;
        }
    }
}
