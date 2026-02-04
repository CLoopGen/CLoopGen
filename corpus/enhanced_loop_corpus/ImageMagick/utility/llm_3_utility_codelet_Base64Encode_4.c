#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char Base64[];
extern  unsigned char *blob;
extern  size_t blob_length;
extern char *encode;
extern  unsigned char *p;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal (processing every 3 bytes from end towards start)
    ptrdiff_t stride = 3;
    ptrdiff_t num_steps = (blob_length - 2) / stride;
    for (ptrdiff_t step = 0; step < num_steps; ++step) {
        ptrdiff_t idx = (blob_length - 2) - (step + 1) * stride; // Reverse index
        unsigned char b0 = blob[idx];
        unsigned char b1 = blob[idx + 1];
        unsigned char b2 = blob[idx + 2];

        encode[i++] = Base64[(int)(b0 >> 2)];
        encode[i++] = Base64[(int)(((b0 & 3) << 4) + (b1 >> 4))];
        encode[i++] = Base64[(int)(((b1 & 15) << 2) + (b2 >> 6))];
        encode[i++] = Base64[(int)(b2 & 63)];
    }
}
