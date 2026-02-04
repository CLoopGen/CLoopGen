#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 carry = ftab[0];
    for (i = 1; i < 257; i++) {
        Int32 next_carry = ftab[i];
        ftab[i] += carry;
        carry = next_carry;
    }
}
