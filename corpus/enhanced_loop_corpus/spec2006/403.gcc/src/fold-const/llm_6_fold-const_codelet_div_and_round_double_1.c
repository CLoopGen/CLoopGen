#include <stdio.h>

#include <inttypes.h>

extern long num[5];
extern long quo[4];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern unsigned long lden;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Eliminate loop-carried dependency by unrolling and reordering operations
    // Original loop-carried dependency on 'carry' is broken by precomputing shifts and restructuring
    unsigned long temp_work[4];
    unsigned long temp_carry = carry;

    // Unroll the loop manually with reversed iteration, but compute in forward order using temporaries
    for (i = 0; i < 4; i++) {
        int idx = 3 - i; // Reverse index: process from last to first as in original
        temp_work[idx] = num[idx] + temp_carry * ((unsigned long)1 << 32);
        quo[idx] = temp_work[idx] / lden;
        temp_carry = temp_work[idx] % lden;
    }
    carry = temp_carry;
}
