#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < (6 + 3) - 1; i++)
        *b++ = a[i * 2];  // Read from strided positions in 'a', write sequentially to 'b'
}
