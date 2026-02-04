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
    // Variant 2: Strided Memory Access Pattern with Interleaved Chroma Updates
    // Access luminance and chroma arrays with fixed stride patterns to simulate tiled processing.
    // Use indirect indexing via base pointers with constant strides to enhance data parallelism potential.

    const int LUM_STRIDE = wrap;
    const int P_STRIDE = wrap3;
    unsigned char *lum_base = lum;
    unsigned char *p_base = p;
    unsigned char *cb_ptr = cb;
    unsigned char *cr_ptr = cr;

    // Pre-compute RGB to YUV constants
    const int C_R_Y = (int)(0.299 * 256 + 0.5);
    const int C_G_Y = (int)(0.587 * 256 + 0.5);
    const int C_B_Y = (int)(0.114 * 256 + 0.5);
    const int C_R_Cb = (int)(0.16874 * 256 + 0.5);
    const int C_G_Cb = (int)(0.33126 * 256 + 0.5);
    const int C_B_Cb = (int)(0.5 * 256 + 0.5);
    const int C_R_Cr = (int)(0.5 * 256 + 0.5);
    const int C_G_Cr = (int)(0.41869 * 256 + 0.5);
    const int C_B_Cr = (int)(0.08131 * 256 + 0.5);

    for (y = 0; y < height; y += 2) {
        for (x = 0; x < width; x += 2) {
            // Strided access: explicitly index into current 2x2 pixel block
            int r0 = p_base[0];       int g0 = p_base[1];       int b0 = p_base[2];
            int r1 = p_base[3];       int g1 = p_base[4];       int b1 = p_base[5];
            int r2 = p_base[P_STRIDE + 0]; int g2 = p_base[P_STRIDE + 1]; int b2 = p_base[P_STRIDE + 2];
            int r3 = p_base[P_STRIDE + 3]; int g3 = p_base[P_STRIDE + 4]; int b3 = p_base[P_STRIDE + 5];

            // Compute luma for each pixel individually with strided store
            lum_base[0] = (C_R_Y * r0 + C_G_Y * g0 + C_B_Y * b0 + 128) >> 8;
            lum_base[1] = (C_R_Y * r1 + C_G_Y * g1 + C_B_Y * b1 + 128) >> 8;
            lum_base[LUM_STRIDE + 0] = (C_R_Y * r2 + C_G_Y * g2 + C_B_Y * b2 + 128) >> 8;
            lum_base[LUM_STRIDE + 1] = (C_R_Y * r3 + C_G_Y * g3 + C_B_Y * b3 + 128) >> 8;

            // Average chroma over 2x2 block
            int rt = r0 + r1 + r2 + r3;
            int gt = g0 + g1 + g2 + g3;
            int bt = b0 + b1 + b2 + b3;

            // Store chroma with unit stride (Cb/Cr written sequentially)
            *cb_ptr++ = ((-C_R_Cb * rt - C_G_Cb * gt + C_B_Cb * bt + 511) >> 10) + 128;
            *cr_ptr++ = ((C_R_Cr * rt - C_G_Cr * gt - C_B_Cr * bt + 511) >> 10) + 128;

            // Advance base pointers by 2 pixels horizontally
            p_base += 6;
            lum_base += 2;
        }
        // Advance to next two rows
        p_base += P_STRIDE - 3 * width;
        lum_base += LUM_STRIDE - width;
    }
}
