#include <stdio.h>

#include <inttypes.h>

extern unsigned long pow2_numbits;
extern unsigned long pow2_flag;
extern int j;
extern int pow2_shifts;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern using a larger buffer with stride of 8
    unsigned long buffer[128]; // Larger buffer for strided access
    int stride = 8;
    unsigned long temp = pow2_numbits;

    // Initialize buffer with dummy values to simulate real memory usage
    for (int i = 0; i < 128; i++) {
        buffer[i] = (i % 2) ? temp : ~temp;
    }

    for (j = 0; j < (8 * 8); j += 2) {
        // Strided read: access every 8th element
        pow2_flag &= buffer[j * stride / 2];
        pow2_shifts += (int)(buffer[j * stride / 2] & 1);
        temp >>= 1;
        if (j + 1 < (8 * 8)) {
            pow2_shifts += (int)(temp & 1);
        }
    }
    pow2_numbits = temp;
}
