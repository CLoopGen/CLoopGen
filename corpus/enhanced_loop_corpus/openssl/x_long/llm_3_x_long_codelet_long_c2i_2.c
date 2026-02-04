#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cont;
extern int len;
extern int i;
extern unsigned long utmp;
extern unsigned long sign;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via reverse order)
    // Simulating indirect access by accessing elements from end to start (reverse indexing)
    utmp = 0; // Initialize accumulator
    for (i = 0; i < len; i++) {
        int idx = len - 1 - i; // Reverse access: indirect-like pattern
        utmp <<= 8;
        utmp |= cont[idx] ^ sign;
    }
}
