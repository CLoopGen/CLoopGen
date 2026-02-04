#include <stdio.h>

#include <inttypes.h>

extern unsigned long *ap;
extern unsigned long *rp;
extern unsigned long carry;
extern int nl;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nl; i++) {
        rp[i] = (carry & ap[i]) | (~carry & rp[i]);
        ap[i] = 0;
        if (carry == 0) break;
    }
}
