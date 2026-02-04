#include <stdio.h>

#include <inttypes.h>

extern  char *asc;
extern int ulen;
extern int i;
extern unsigned char *unitmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling to process two elements at a time
    int limit = ulen - 2;
    for (i = 0; i < limit; i += 4) {
        // Unroll to write consecutive bytes in unitmp
        if (i + 2 < limit) {
            unitmp[i]     = 0;
            unitmp[i + 1] = asc[i >> 1];
            unitmp[i + 2] = 0;
            unitmp[i + 3] = asc[(i + 2) >> 1];
        } else {
            unitmp[i] = 0;
            unitmp[i + 1] = asc[i >> 1];
        }
    }
}
