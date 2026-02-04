#include <stdio.h>

#include <inttypes.h>

extern unsigned char *data;
extern int i;
extern unsigned long *p;
extern unsigned long ri;
extern unsigned char *d;
extern unsigned char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – read every 2nd byte, wrapping appropriately
    // Effectively creates a strided pattern with stride=2, reading 4 non-consecutive bytes
    unsigned char *stride_d = d;
    int stride = 2;
    int total_needed_bytes = 4 * stride;
    unsigned char buf[4];

    for (i = 0; i < (16 + 2); i++) {
        ri = 0;
        // Extract 4 bytes with strided access
        for (int j = 0; j < 4; j++) {
            unsigned char *ptr = stride_d + j * stride;
            // Handle wrap-around for strided pointer
            while (ptr >= end) {
                ptr = data + (ptr - end);
            }
            buf[j] = *ptr;
            ri = (ri << 8) | buf[j];
        }
        // Advance base pointer by total span (with wrap)
        stride_d += total_needed_bytes;
        while (stride_d >= end) {
            stride_d = data + (stride_d - end);
        }
        p[i] ^= ri;
    }
    d = stride_d;
}
