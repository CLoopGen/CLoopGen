#include <stdio.h>

#include <inttypes.h>

extern  uint64_t *a;
extern  uint64_t *b;
extern uint64_t aa[4];
extern uint64_t bb[4];
extern uint64_t bbb[4];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        aa[i] = a[i] + a[i + 4];
        bb[i] = aa[i] + b[i];           // Introduced RAW dependency on aa[i]
        bbb[i] = bb[i] + b[i + 4];      // Maintains use of bb[i], no loop-carried dep
    }
}
