#include <stdio.h>

#include <inttypes.h>

extern unsigned long *ap;
extern unsigned long *rp;
extern unsigned long carry;
extern int nl;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < nl; i++) {
    for (j = 0; j < 2; j++) {
        if (j == 0) {
            rp[i] = (carry & ap[i]) | (~carry & rp[i]);
        } else {
            ap[i] = 0;
        }
    }
}
}
