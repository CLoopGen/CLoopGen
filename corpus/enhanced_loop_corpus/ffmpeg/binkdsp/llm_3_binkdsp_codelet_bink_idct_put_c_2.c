#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest;
extern int linesize;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Index Remapping
    int idx[8];
    // Precompute strided indices assuming non-linear access pattern
    for (i = 0; i < 8; i++) {
        idx[i] = i * linesize; // Could be modified to irregular strides if needed
    }

    for (i = 0; i < 8; i++) {
        const int base = 8 * i;
        const int a0 = temp[base + 0] + temp[base + 4];
        const int a1 = temp[base + 0] - temp[base + 4];
        const int a2 = temp[base + 2] + temp[base + 6];
        const int a3 = ((int)((unsigned int)(2896) * (temp[base + 2] - temp[base + 6])) >> 11);
        const int a4 = temp[base + 5] + temp[base + 3];
        const int a5 = temp[base + 5] - temp[base + 3];
        const int a6 = temp[base + 1] + temp[base + 7];
        const int a7 = temp[base + 1] - temp[base + 7];
        const int b0 = a4 + a6;
        const int b1 = ((int)((unsigned int)(3784) * (a5 + a7)) >> 11);
        const int b2 = ((int)((unsigned int)(-5352) * a5) >> 11) - b0 + b1;
        const int b3 = ((int)((unsigned int)(2896) * (a6 - a4)) >> 11) - b2;
        const int b4 = ((int)((unsigned int)(2217) * a7) >> 11) + b3 - b1;

        // Use strided destination access via precomputed index array
        dest[idx[0] + i] = ((a0 + a2 + b0) + 127) >> 8;
        dest[idx[1] + i] = ((a1 + a3 - a2 + b2) + 127) >> 8;
        dest[idx[2] + i] = ((a1 - a3 + a2 + b3) + 127) >> 8;
        dest[idx[3] + i] = ((a0 - a2 - b4) + 127) >> 8;
        dest[idx[4] + i] = ((a0 - a2 + b4) + 127) >> 8;
        dest[idx[5] + i] = ((a1 - a3 + a2 - b3) + 127) >> 8;
        dest[idx[6] + i] = ((a1 + a3 - a2 - b2) + 127) >> 8;
        dest[idx[7] + i] = ((a0 + a2 - b0) + 127) >> 8;
    }
}
