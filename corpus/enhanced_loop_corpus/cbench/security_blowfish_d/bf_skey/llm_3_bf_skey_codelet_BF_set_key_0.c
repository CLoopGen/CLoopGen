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
    // Variant 2: Strided access pattern - process elements with a fixed stride across p and simulate strided input fetch
    int stride = 2;
    int n = (16 + 2);
    unsigned char *local_d = d;
    unsigned char *local_data = data;
    unsigned long *local_p = p;
    int j;

    // Process indices in a strided manner, wrapping around using modulo
    for (j = 0; j < n; j++) {
        int idx = (j * stride) % n;  // Strided index into p[]
        unsigned long ri_val = 0;

        // Fetch 4 bytes with automatic wraparound using modulo-like logic
        for (int b = 0; b < 4; b++) {
            ri_val <<= 8;
            ri_val |= *local_d++;
            if (local_d >= end)
                local_d = local_data;
        }

        local_p[idx] ^= ri_val;
    }

    d = local_d;  // Update global pointer
}
