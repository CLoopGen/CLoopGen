#include <stdio.h>

#include <inttypes.h>

extern int i;
extern long n;
extern size_t resp_len;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order memory access
    // Traverse the array from the end to the beginning using consecutive indices.
    // This maintains data dependency and bit-shifting logic but changes access order.
    for (i = 0; i < n; i++) {
        resp_len <<= 8;
        resp_len |= p[n - 1 - i];  // Access from end to start
    }
}
