#include <stdio.h>

#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

typedef int int32;

typedef struct {
    TIFFRGBValue *clamptab;
    int *Cr_r_tab;
    int *Cb_b_tab;
    int32 *Cr_g_tab;
    int32 *Cb_g_tab;
    float coeffs[3];
} TIFFYCbCrToRGB;

extern TIFFYCbCrToRGB *ycbcr;
extern int i;
extern int32 D1;
extern int32 D2;
extern int32 D3;
extern int32 D4;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified expressions and reduced trip count
    // Also precomputes common shift value to reduce redundancy
    const int32 offset = (int32)(1 << (16 - 1));
    for (i = 0, x = -128; i < 128; i++, x += 2) {
        // Only compute every other index, reducing total operations
        // Merge some computations by reusing intermediate values
        int32 scaled_x = (int32)x;
        int cr_r_val = (int)((D1 * scaled_x + offset) >> 16);
        int cb_b_val = (int)((D3 * scaled_x + offset) >> 16);

        ycbcr->Cr_r_tab[i] = cr_r_val;
        ycbcr->Cb_b_tab[i] = cb_b_val;
        ycbcr->Cr_g_tab[i] = D2 * scaled_x;
        ycbcr->Cb_g_tab[i] = D4 * scaled_x + offset;
    }
}
