#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cont;
extern int len;
extern int i;
extern unsigned long utmp;
extern unsigned long sign;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward traversal)
    utmp = 0; // Initialize accumulator
    for (i = 0; i < len; i += 2) {
        utmp <<= 8;
        if (i < len) utmp |= cont[i] ^ sign;
        utmp <<= 8;
        if (i + 1 < len) utmp |= cont[i + 1] ^ sign;
    }
}
