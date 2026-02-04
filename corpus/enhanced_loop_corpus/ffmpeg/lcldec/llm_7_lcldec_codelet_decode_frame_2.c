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
    yq = encoded[pixel_ptr++];
    uqvq = (((const union unaligned_16 *)(encoded + pixel_ptr))->l);
    pixel_ptr += 2;
    for (col = 1; col < width; col++) {
        uint16_t current_uqvq_val = (((const union unaligned_16 *)(encoded + pixel_ptr + 1))->l);
        yq -= encoded[pixel_ptr];
        encoded[pixel_ptr] = yq;
        uqvq -= current_uqvq_val;
        pixel_ptr += 3;
        ((((union unaligned_16 *)(encoded + pixel_ptr - 2))->l) = (uqvq));
    }
}
}
