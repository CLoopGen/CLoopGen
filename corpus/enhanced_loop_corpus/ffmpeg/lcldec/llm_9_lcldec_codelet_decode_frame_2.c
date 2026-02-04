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
for (row = 0; row < height; row += 2) {
    if (row + 1 >= height) break;
    size_t pixel_ptr1 = row * width * 3;
    size_t pixel_ptr2 = (row + 1) * width * 3;
    unsigned char yq1 = encoded[pixel_ptr1++];
    unsigned char yq2 = encoded[pixel_ptr2++];
    int uqvq1 = (((const union unaligned_16 *)(encoded + pixel_ptr1))->l);
    int uqvq2 = (((const union unaligned_16 *)(encoded + pixel_ptr2))->l);
    pixel_ptr1 += 2;
    pixel_ptr2 += 2;
    for (col = 1; col < width; col++) {
        encoded[pixel_ptr1] = yq1 -= encoded[pixel_ptr1];
        encoded[pixel_ptr2] = yq2 -= encoded[pixel_ptr2];
        uqvq1 -= (((const union unaligned_16 *)(encoded + pixel_ptr1 + 1))->l);
        uqvq2 -= (((const union unaligned_16 *)(encoded + pixel_ptr2 + 1))->l);
        ((((union unaligned_16 *)(encoded + pixel_ptr1 + 1))->l) = (uqvq1));
        ((((union unaligned_16 *)(encoded + pixel_ptr2 + 1))->l) = (uqvq2));
        pixel_ptr1 += 3;
        pixel_ptr2 += 3;
    }
}
}
