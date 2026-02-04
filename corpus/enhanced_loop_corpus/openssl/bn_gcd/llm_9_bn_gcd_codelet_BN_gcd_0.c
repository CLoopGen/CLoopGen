#include <stdio.h>

#include <inttypes.h>

extern unsigned long pow2_numbits;
extern unsigned long pow2_flag;
extern int j;
extern int pow2_shifts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < (8 * 8) / 2; j++) {
        unsigned long temp = pow2_numbits >> 1;
        pow2_flag = pow2_flag & temp;
        pow2_shifts += (int)(pow2_flag & 3);
        pow2_numbits = temp >> 1;
        pow2_shifts += (int)(pow2_flag & 1);
    }
}
