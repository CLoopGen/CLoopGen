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



void loop(){
for (y = 0; y < height; y += 2) {
    // Variant 2: Eliminate all WAW and WAR hazards by using temporary arrays and full unrolling
    // Remove loop-carried dependencies entirely for better parallelism
    unsigned char temp_lum[4];
    int temp_rgb[3] = {0};

    for (x = 0; x < width; x += 2) {
        // Process 2x2 block independently without immediate memory updates
        const unsigned char* p0 = p;
        const unsigned char* p1 = p + wrap3;

        // Top-left pixel
        r = p0[0]; g = p0[1]; b = p0[2];
        temp_lum[0] = (((int)(0.299 * 256 + 0.5)) * r + 
                       ((int)(0.587 * 256 + 0.5)) * g + 
                       ((int)(0.114 * 256 + 0.5)) * b + 128) >> 8;
        temp_rgb[0] += r; temp_rgb[1] += g; temp_rgb[2] += b;

        // Top-right pixel
        r = p0[3]; g = p0[4]; b = p0[5];
        temp_lum[1] = (((int)(0.299 * 256 + 0.5)) * r + 
                       ((int)(0.587 * 256 + 0.5)) * g + 
                       ((int)(0.114 * 256 + 0.5)) * b + 128) >> 8;
        temp_rgb[0] += r; temp_rgb[1] += g; temp_rgb[2] += b;

        // Bottom-left pixel
        r = p1[0]; g = p1[1]; b = p1[2];
        temp_lum[2] = (((int)(0.299 * 256 + 0.5)) * r + 
                       ((int)(0.587 * 256 + 0.5)) * g + 
                       ((int)(0.114 * 256 + 0.5)) * b + 128) >> 8;
        temp_rgb[0] += r; temp_rgb[1] += g; temp_rgb[2] += b;

        // Bottom-right pixel
        r = p1[3]; g = p1[4]; b = p1[5];
        temp_lum[3] = (((int)(0.299 * 256 + 0.5)) * r + 
                       ((int)(0.587 * 256 + 0.5)) * g + 
                       ((int)(0.114 * 256 + 0.5)) * b + 128) >> 8;
        temp_rgb[0] += r; temp_rgb[1] += g; temp_rgb[2] += b;

        // Write luminance values only after all computations (eliminates WAW)
        lum[0] = temp_lum[0];
        lum[1] = temp_lum[1];
        lum[wrap] = temp_lum[2];
        lum[wrap + 1] = temp_lum[3];

        // Compute chroma from local sum (no dependency on prior blocks)
        int r_total = temp_rgb[0], g_total = temp_rgb[1], b_total = temp_rgb[2];
        cb[0] = ((-43 * r_total - 85 * g_total + 128 * b_total + 2048) >> 10) + 128;
        cr[0] = ((128 * r_total - 107 * g_total - 21 * b_total + 2048) >> 10) + 128;

        // Reset temp sum for next independent block
        temp_rgb[0] = temp_rgb[1] = temp_rgb[2] = 0;

        // Advance pointers
        p += 6;
        lum += 2;
        cb++;
        cr++;
    }
    p += wrap3;
    lum += wrap;
}
}
