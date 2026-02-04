#include <stdio.h>
#include <inttypes.h>

unsigned short *x;
int i;
unsigned short newbyt;
unsigned short oldbyt;
static unsigned short data[131072]; // 256KB of data (131072 elements * 2 bytes)

void init_vars() {
    x = &data[131071]; // Point to last element to allow decrementing in loop
    i = 0;
    newbyt = 0xABCD;
    oldbyt = 0x1234;

    // Initialize all data elements to prevent undefined behavior
    for (int j = 0; j < 131072; ++j) {
        data[j] = 0xFFFF;
    }
}