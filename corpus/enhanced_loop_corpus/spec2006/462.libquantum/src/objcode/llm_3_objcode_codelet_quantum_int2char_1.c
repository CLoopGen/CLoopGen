#include <stdio.h>

#include <inttypes.h>

extern int j;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access – write every 2nd byte, alternating fill
    for (i = 0; i < size; i += 2) {
        int effective_index = (i / 2) * 2; // Ensures even indices only
        int shift_amount = (size - i - 1) * 8;
        if (shift_amount < 0) shift_amount = 0;
        buf[effective_index] = (i < size) ? (j >> shift_amount) & 0xFF : 0;
        j %= (1 << shift_amount);
    }
    // Second pass for odd indices to simulate strided population
    for (i = 1; i < size; i += 2) {
        int shift_amount = (size - i - 1) * 8;
        if (shift_amount < 0) shift_amount = 0;
        buf[i] = (j >> shift_amount) & 0xFF;
        j %= (1 << shift_amount);
    }
}
