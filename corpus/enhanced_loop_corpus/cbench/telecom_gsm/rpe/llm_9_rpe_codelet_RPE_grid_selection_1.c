#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *x;
extern word *xM;
extern int i;
extern word Mc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word idx, base;
    base = Mc;
    for (i = 0; i <= 8; i++) {
        idx = base + 5 * i;
        xM[i] = x[idx];
        xM[i+4] = x[idx + 1];  // Unrolled: two accesses per iteration
    }
}
