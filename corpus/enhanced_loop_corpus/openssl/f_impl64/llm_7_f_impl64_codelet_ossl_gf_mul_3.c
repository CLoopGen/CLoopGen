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
        uint64_t temp_a = a[i] + a[i + 4];
        uint64_t temp_b1 = b[i] + b[i + 4];
        uint64_t temp_b2 = temp_b1 + b[i + 4];  // Eliminated WAW on bb[i], used temp
        aa[i] = temp_a;
        bb[i] = temp_b1;
        bbb[i] = temp_b2;
    } // Removed WAR/WAW hazards by using temporaries; no loop-carried dependencies
}
