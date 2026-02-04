#include <stdio.h>

#include <inttypes.h>

extern unsigned long pow2_numbits;
extern unsigned long pow2_flag;
extern int j;
extern int pow2_shifts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_shifts = pow2_shifts;
    unsigned long local_numbits = pow2_numbits;
    unsigned long local_flag = pow2_flag;

    for (j = 0; j < (8 * 8); j++) {
        local_flag &= local_numbits;
        local_shifts += (int)local_flag;
        local_numbits >>= 1;
    }

    pow2_shifts = local_shifts;
    pow2_numbits = local_numbits;
    pow2_flag = local_flag;
}
