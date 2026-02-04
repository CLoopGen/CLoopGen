#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *data;
extern int i;
extern unsigned int *p;
extern unsigned int ri;
extern  unsigned char *d;
extern  unsigned char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access — read every 2nd byte, effectively creating a stride-2 pattern
    // This changes access pattern from sequential to strided, doubling the effective buffer length usage
    unsigned char *local_d = d;
    unsigned int *local_p = p;
    unsigned char *local_data = data;
    unsigned char *local_end = end;
    int stride = 2;
    int total_bytes = 4 * stride; // 4 reads with stride

    for (i = 0; i < (16 + 2); i++) {
        ri = 0;
        for (int b = 0; b < 4; b++) {
            ri <<= 8;
            ri |= local_d[(b * stride) % (local_end - local_data)];
        }

        // Advance d by total_bytes, handling wrap-around
        local_d += total_bytes;
        while (local_d >= local_end) {
            local_d -= (local_end - local_data);
        }
        
        local_p[i] ^= ri;
    }
    
    d = local_d; // update global d
}
