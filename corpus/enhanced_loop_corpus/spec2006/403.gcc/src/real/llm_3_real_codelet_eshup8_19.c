#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short newbyt;
extern unsigned short oldbyt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (access every second element in reverse order)
    int stride = 2;
    unsigned short temp_oldbyt = oldbyt;
    for (i = 2; i < (6 + 3); i++) {
        int index = (6 + 3) - i; // Reverse index
        unsigned short *access_ptr = x - (index * stride); // Strided backward access
        unsigned short temp_newbyt = *access_ptr >> 8;
        *access_ptr <<= 8;
        *access_ptr |= temp_oldbyt;
        temp_oldbyt = temp_newbyt;
    }
    oldbyt = temp_oldbyt;
}
