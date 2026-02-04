#include <stdio.h>

#include <inttypes.h>

extern unsigned int parts[16];
extern long high;
extern long low;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride and wrap-around indexing
    const int n = (8 * 8) / 8;
    const int stride = 3;  // Access every 3rd element modulo array size
    for (i = 0; i < n; i++) {
        int idx_low = (i * stride) % n;
        int idx_high = n + ((i * stride) % n);
        low |= (long)parts[idx_low] << (i * 8);
        high |= (long)parts[idx_high] << (i * 8);
    }
}
