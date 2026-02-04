#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern unsigned int pixel_ptr;
extern int row;
extern int col;
extern unsigned char *encoded;
extern int width;
extern int height;
extern unsigned char yq;
extern int uqvq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flatten the original nested loop by merging iteration spaces (reduce nesting depth)
// Combine row and col into a single linear traversal

pixel_ptr = 0;
yq = 0;
uqvq = 0;

for (int idx = 0; idx < height * width; idx++) {
    row = idx / width;
    col = idx % width;

    if (col == 0) {
        // First pixel in row: initialize yq and uqvq
        pixel_ptr = row * width * 3;
        yq = encoded[pixel_ptr++];
        uqvq = (((const union unaligned_16 *)(encoded + pixel_ptr))->l);
        pixel_ptr += 2;
    } else {
        // Subsequent pixels: apply prediction delta coding
        encoded[pixel_ptr] = yq -= encoded[pixel_ptr];
        uqvq -= (((const union unaligned_16 *)(encoded + pixel_ptr + 1))->l);
        ((((union unaligned_16 *)(encoded + pixel_ptr + 1))->l) = (uqvq));
        pixel_ptr += 3;
    }
}
}
