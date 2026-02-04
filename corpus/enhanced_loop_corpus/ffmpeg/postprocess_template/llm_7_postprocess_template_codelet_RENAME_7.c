#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 8; x++) {
    int t1 = x * x;           // Independent computation
    int t2 = (x + 1) * 10;    // No dependency on t1 (eliminated RAW)
    int t3 = (x + 2) * 5;     // No dependency on t2 (eliminated chain)
    t1 = t3 + 1;              // WAW hazard introduced: reassignment to t1 after init
    // No loop-carried dependencies: each iteration is independent
}
}
