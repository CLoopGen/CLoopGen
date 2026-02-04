#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cont;
extern int len;
extern int i;
extern unsigned long utmp;
extern unsigned long sign;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long local_accum = 0;
    for (i = 0; i < len; i++) {
        unsigned char masked = cont[i] ^ sign;
        local_accum = (local_accum << 8) | masked;
    }
    utmp = local_accum;
    // Removed loop-carried dependency on global 'utmp' during iterations by using a local accumulator
    // Eliminated intra-loop WAW and RAW on shared 'utmp', reducing data dependencies across iterations
    // Assignment to 'utmp' only after loop completes — no loop-carried dependency on external state
}
