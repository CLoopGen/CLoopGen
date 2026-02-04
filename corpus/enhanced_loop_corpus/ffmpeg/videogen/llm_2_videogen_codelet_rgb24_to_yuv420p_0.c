#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *lum;
extern unsigned char *cb;
extern unsigned char *cr;
extern int width;
extern int height;
extern int wrap;
extern int wrap3;
extern int x;
extern int y;
extern int r;
extern int g;
extern int b;
extern int r1;
extern int g1;
extern int b1;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access via wrap and wrap3, reorganize data access to be consecutive.
    // We assume that the image data is now laid out in a fully planar format (lum, cb, cr stored separately as contiguous blocks).
    // This variant eliminates pointer arithmetic with wrap/wrap3 by precomputing row offsets.

    int lum_offset = 0;
    int chroma_offset = 0;
    int pixel_offset = 0;

    for (y = 0; y < height; y += 2) {
        for (x = 0; x < width; x += 2) {
            pixel_offset = (y * width + x) * 3; // RGB interleaved input

            r = p[pixel_offset + 0];
            g = p[pixel_offset + 1];
            b = p[pixel_offset + 2];
            r1 = r;
            g1 = g;
            b1 = b;

            lum[lum_offset + 0] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + 
                                   ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + 
                                   ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

            r = p[pixel_offset + 3];
            g = p[pixel_offset + 4];
            b = p[pixel_offset + 5];
            r1 += r;
            g1 += g;
            b1 += b;

            lum[lum_offset + 1] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + 
                                  ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + 
                                  ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

            r = p[pixel_offset + width * 3 + 0];
            g = p[pixel_offset + width * 3 + 1];
            b = p[pixel_offset + width * 3 + 2];
            r1 += r;
            g1 += g;
            b1 += b;

            lum[lum_offset + wrap] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + 
                                     ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + 
                                     ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

            r = p[pixel_offset + width * 3 + 3];
            g = p[pixel_offset + width * 3 + 4];
            b = p[pixel_offset + width * 3 + 5];
            r1 += r;
            g1 += g;
            b1 += b;

            lum[lum_offset + wrap + 1] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + 
                                         ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + 
                                         ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

            cb[chroma_offset] = ((-((int)((0.16874) * (1 << 8) + 0.5)) * r1 - 
                                 ((int)((0.33126) * (1 << 8) + 0.5)) * g1 + 
                                 ((int)((0.5) * (1 << 8) + 0.5)) * b1 + 4 * (1 << (8 - 1)) - 1) >> (8 + 2)) + 128;

            cr[chroma_offset] = ((((int)((0.5) * (1 << 8) + 0.5)) * r1 - 
                                 ((int)((0.41869000000000001) * (1 << 8) + 0.5)) * g1 - 
                                 ((int)((0.081309999999999993) * (1 << 8) + 0.5)) * b1 + 4 * (1 << (8 - 1)) - 1) >> (8 + 2)) + 128;

            lum_offset += 2;
            chroma_offset++;
        }
        lum_offset += wrap; // account for next two rows
    }
}
