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
        drpp = (((((longword)(brp) * (longword)(drp[k - Nr]) + 16384)) >> (15)));
        drp[k] = ((ulongword)((ltmp = (longword)(erp[k]) + (longword)(drpp)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
    }
    for (k = 20; k <= 39; k++) {
        drpp = (((((longword)(brp) * (longword)(drp[k - Nr]) + 16384)) >> (15)));
        drp[k] = ((ulongword)((ltmp = (longword)(erp[k]) + (longword)(drpp)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
    }
}
