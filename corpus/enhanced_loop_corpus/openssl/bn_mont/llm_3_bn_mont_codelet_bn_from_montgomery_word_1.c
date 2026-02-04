#include <stdio.h>

#include <inttypes.h>

extern unsigned long *ap;
extern unsigned long *rp;
extern unsigned long carry;
extern int nl;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from end to beginning
    for (i = nl - 1; i >= 0; i--) {
        rp[i] = (carry & ap[i]) | (~carry & rp[i]);
        ap[i] = 0;
    }
}
