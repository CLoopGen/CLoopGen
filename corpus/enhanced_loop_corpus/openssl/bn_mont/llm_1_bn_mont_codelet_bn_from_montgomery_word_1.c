#include <stdio.h>

#include <inttypes.h>

extern unsigned long *ap;
extern unsigned long *rp;
extern unsigned long carry;
extern int nl;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (nl > 0) {
    for (i = 0; i < nl; i += 2) {
        int upper = (i + 1 < nl) ? i + 1 : i;
        for (int k = i; k <= upper; k++) {
            rp[k] = (carry & ap[k]) | (~carry & rp[k]);
            ap[k] = 0;
        }
    }
}
}
