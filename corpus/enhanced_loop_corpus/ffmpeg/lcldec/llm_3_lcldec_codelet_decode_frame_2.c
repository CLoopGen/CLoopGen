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
for (row = 0; row < height; row++) {
    pixel_ptr = row * width * 3;
    yq = encoded[pixel_ptr];
    uqvq = (((const union unaligned_16 *)(encoded + pixel_ptr + 1))->l);
    for (col = 0; col < width; col++) {
        int current_offset = pixel_ptr + col * 3;
        int prev_offset = (col == 0) ? current_offset : pixel_ptr + (col - 1) * 3;
        if (col > 0) {
            encoded[current_offset] = yq -= encoded[current_offset];
            uqvq -= (((const union unaligned_16 *)(encoded + current_offset + 1))->l);
            ((((union unaligned_16 *)(encoded + current_offset + 1))->l) = (uqvq));
        }
    }
}
}
