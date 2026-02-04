#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int pixel_ptr;
extern int row;
extern int col;
extern unsigned char *encoded;
extern int width;
extern int height;
extern unsigned char yq;
extern unsigned char uq;
extern unsigned char vq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (row = 0; row < height; row++) {
    yq = uq = vq = 0;
    unsigned char yq_next, uq_next, vq_next;
    for (col = 0; col < width / 4; col++) {
        yq_next = yq - encoded[pixel_ptr];
        encoded[pixel_ptr] = yq_next;
        yq_next = yq_next - encoded[pixel_ptr + 1];
        encoded[pixel_ptr + 1] = yq_next;
        yq_next = yq_next - encoded[pixel_ptr + 2];
        encoded[pixel_ptr + 2] = yq_next;
        yq_next = yq_next - encoded[pixel_ptr + 3];
        encoded[pixel_ptr + 3] = yq_next;

        uq_next = uq - encoded[pixel_ptr + 4];
        encoded[pixel_ptr + 4] = uq_next;
        uq_next = uq_next - encoded[pixel_ptr + 5];
        encoded[pixel_ptr + 5] = uq_next;

        vq_next = vq - encoded[pixel_ptr + 6];
        encoded[pixel_ptr + 6] = vq_next;
        vq_next = vq_next - encoded[pixel_ptr + 7];
        encoded[pixel_ptr + 7] = vq_next;

        yq = yq_next;
        uq = uq_next;
        vq = vq_next;

        pixel_ptr += 8;
    }
}
}
